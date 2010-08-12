#ifndef PACKAGEVERSION_H
#define PACKAGEVERSION_H

#include "qxml.h"
#include "qstring.h"
#include "qmetatype.h"
#include "qdir.h"
#include "qurl.h"
#include "qstringlist.h"

#include "job.h"
#include "packageversionfile.h"
#include "version.h"

class PackageVersion
{
private:
    bool unzip(QString zipfile, QString outputdir, QString* errMsg);
    bool createShortcuts(QString* errMsg);
    void deleteShortcuts();
    bool saveFiles(QString* errMsg);
    bool executeFile(QString& path, QString* errMsg);

    QString fullText;
public:
    /** package version */
    Version version;

    /** complete package name like net.sourceforge.NotepadPlusPlus */
    QString package;

    /** important files (shortcuts for these will be created in the menu) */
    QStringList importantFiles;

    /** titles for the important files */
    QStringList importantFilesTitles;

    /**
     * Packages.
     */
    QList<PackageVersionFile*> files;

    /** 0 = zip file, 1 = one file */
    int type;

    PackageVersion();
    PackageVersion(const QString& package);
    virtual ~PackageVersion();

    /**
     * @return package title
     */
    QString getPackageTitle();

    /**
     * @return only the last part of the package name (without a dot)
     */
    QString getShortPackageName();

    /**
     * @return true if this package version is installed
     */
    bool installed();

    /**
     * @return directory where this package version should be installed
     */
    QDir getDirectory();

    /**
     * @return description that can be used for the full-text search in lower
     *     case
     */
    QString getFullText();

    /**
     * .zip file for downloading
     */
    QUrl download;

    /**
     * Installs this application.
     *
     * @param job job for this method
     */
    void install(Job* job);

    /**
     * Uninstalls this package version.
     *
     * @param job job for this method
     */
    void uninstall(Job* job);

    /**
     * Updates this version to the newest available.
     *
     * @param job job for this method
     */
    void update(Job* job);
};

Q_DECLARE_METATYPE(PackageVersion);

#endif // PACKAGEVERSION_H
