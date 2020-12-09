#include "Translator.h"
#include <QTranslator>
#include <QCoreApplication>
#include <QLoggingCategory>
#include <QMutex>
#include <QMutexLocker>
#include <QLocale>
#include <QFileInfo>
#include <QDir>
#include <QLibraryInfo>

namespace {
Q_LOGGING_CATEGORY(loggingCategory, "ts.translator")
} // unnamed namespace

namespace {
QMutex mutex;
QTranslator *qtTs = nullptr;
QTranslator *apTs = nullptr;
}

Translator::Translator(QObject *parent)
	: QObject(parent)
{
	QMutexLocker lock(&mutex);
	if (qtTs == nullptr) {
		if (qApp->startingUp()) {
			qCWarning(loggingCategory) << "Instanciate QCoreApplication before constract this class.";
			return;
		}
		qtTs = new QTranslator(qApp);
		apTs = new QTranslator(qApp);
		qApp->installTranslator(qtTs);
		qApp->installTranslator(apTs);
	}
}

QList<QLocale> Translator::availableLanguages() const
{
	auto files = QDir(qApp->applicationDirPath() + "/translations").entryInfoList({QString("%1_*.qm").arg(qAppName())}, QDir::Files | QDir::NoDotAndDotDot);
	QList<QLocale> result;
	for (const auto &file : files) {
		result << QLocale(file.baseName().right(5));
	}
	return result;
}

void Translator::setLanguage(const QString &name)
{
	qCDebug(loggingCategory) << "set language" << name;
	qtTs->load("qt_" + name, qApp->applicationDirPath() + "/translations");
	apTs->load(QString("%1_%2").arg(qAppName()).arg(name), qApp->applicationDirPath() + "/translations");
}
