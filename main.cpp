/*C:\local\boost_1_65_1
C:\Program Files\MySQL\MySQL Server 5.7\include
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include
I:\vs2015\VC\include
I:\vs2015\VC\atlmfc\include
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10150.0\ucrt
C:\Program Files (x86)\Windows Kits\8.1\Include\um
C:\Program Files (x86)\Windows Kits\8.1\Include\shared
C:\Program Files (x86)\Windows Kits\8.1\Include\winrt*/
/*C:\local\boost_1_65_1
C:\Program Files\MySQL\MySQL Server 5.7\lib
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\lib
I:\vs2015\VC\lib\amd64
I:\vs2015\VC\atlmfc\lib\amd64
C:\Program Files (x86)\Windows Kits\10\lib\10.0.10150.0\ucrt\x64
C:\Program Files (x86)\Windows Kits\8.1\lib\winv6.3\um\x64
C:\Program Files (x86)\Windows Kits\NETFXSDK\4.6\Lib\um\x64*/
/*C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtWebEngineWidgets
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtWebChannel
.
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtWidgets
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtGui
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtANGLE
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\include\QtCore
debug
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\mkspecs\win32-msvc
%(AdditionalIncludeDirectories)*/
/*libmysql.lib
Qt5WebChanneld.lib
Qt5WebEngined.lib
Qt5WebEngineWidgetsd.lib
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\lib\qtmaind.lib
shell32.lib
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\lib\Qt5Widgetsd.lib
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\lib\Qt5Guid.lib
C:\Qt\Qt5.9.2\5.9.2\msvc2015_64\lib\Qt5Cored.lib
%(AdditionalDependencies)*/


#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QPixmap>
#include <QSplashScreen>
//#include "correction.h"
//#include "picshow.h"
//#include "mysql_con.h"
#include "mysql_pannel.h"
#include "search_w.h"
#include "search_wizard.h"
#include "network_pannel.h"
#include "result_window.h"

extern int userstatus;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
#ifndef QT_NO_TRANSLATION
	/*本地化处理*/
	QString translatorFileName = QLatin1String("qt_");
	translatorFileName += QLocale::system().name();
	QTranslator *translator = new QTranslator(&app);
	if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
		app.installTranslator(translator);
#endif
	//-result_window rw;
	//-rw.show();
	//search_wizard swizard;
	//swizard.show();

	QPixmap pixmap("cover/cover1.jpg");
	QSplashScreen splash(pixmap);
	
	splash.show();
	app.processEvents();
	MainWindow w;
	////correction w1;
	////picshow p;
	////p.show();
	w.show();
	splash.finish(&w);

	//-mysql_pannel pa;
	//-pa.show();
	//search_w sw;
	//sw.show();
	//mysql_test();
	//w1.show();
	//NetWork nkw;
	//nkw.show();
	return app.exec();
}
