#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "translator_global.h"
#include <QtCore/QObject>
#include <QtCore/QLocale>

class TRANSLATOR_EXPORT Translator : public QObject
{
	Q_OBJECT
public:
	explicit Translator(QObject *parent = Q_NULLPTR);
	Q_INVOKABLE QList<QLocale> availableLanguages() const;

public Q_SLOTS:
	void setLanguage(const QString &name);
};

#endif // TRANSLATOR_H
