#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Translator.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Translator ts;
	for (const auto &lang : ts.availableLanguages()) {
		auto action = ui->menu_Language->addAction(QLocale::languageToString(lang.language()));
		action->setData(lang.name());
	}
	connect(ui->menu_Language, &QMenu::triggered, this, [] (QAction *action) {
		Translator ts;
		ts.setLanguage(action->data().toString());
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}

#include <QEvent>
void MainWindow::changeEvent(QEvent *event)
{
	if (event->type() == QEvent::LanguageChange) {
		auto combo1Index = ui->comboBox->currentIndex();
		ui->retranslateUi(this);
		ui->comboBox->setCurrentIndex(combo1Index);
	}
	QMainWindow::changeEvent(event);
}
