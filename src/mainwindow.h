#ifndef MAINWINDOW_H
#define MAINWINDIW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QList>
#include <QPixmap>
#include <QStackedLayout>
#include <QScrollArea>
#include <QSettings>
#include <QSpacerItem>
#include "mainheader.h"
#include "firstscreen.h"
#include "summary.h"
#include "installscreen.h"
#include "fakebackend.h"
#include "packagebackend.h"
#include "backend.h"

class MainWindow : public QDialog
{
    Q_OBJECT
public:
    /**
        Default Constructor taking the YMP file as argument
    */
    MainWindow( const QString& filename, QString tmpFileName, bool fakeRequested, QObject *parent = 0 );

private:
    PackageBackend *m_backend;
    FirstScreen *m_firstScreen;
    QString *m_tmpFileName;
    MainHeader *m_header;
    QStackedLayout *m_screenStack;

    QHBoxLayout *m_warningLayout;

    QPushButton *m_showSettings;
    QPushButton *m_cancel;
    QPushButton *m_install;

    QSettings m_settings;

    bool m_fakeRequested;

private slots:

    /**
     *  Show the next screen
     */
    void showNextScreen( int index );

    /**
     *  Update the Repository and Package Counts
     */
    void updateCount(int repoCount , int packageCount);

    /**
     * Show the install screen
     */
    void performInstallation();

    /**
     * Show the settings dialog
     */
    void showSettings();

    /**
     * Update the size of packages
     */
    void updateSize(QString size );

signals:
    void countChanged( int repoCount, int packageCount );
};

#endif
