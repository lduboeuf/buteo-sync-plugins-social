/****************************************************************************
 **
 ** Copyright (C) 2014 Jolla Ltd.
 ** Contact: Chris Adams <chris.adams@jollamobile.com>
 **
 ****************************************************************************/

#include "vkcontactimagedownloader.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

static const char *IMAGE_DOWNLOADER_IDENTIFIER_KEY = "identifier";

VKContactImageDownloader::VKContactImageDownloader()
    : AbstractImageDownloader()
{
}

QString VKContactImageDownloader::staticOutputFile(const QString &identifier, const QUrl &url)
{
    return makeUrlOutputFile(SocialSyncInterface::VK, SocialSyncInterface::Contacts, identifier,
                             url.toString(), QString());
}

QNetworkReply * VKContactImageDownloader::createReply(const QString &url,
                                                      const QVariantMap &metadata)
{
    Q_D(AbstractImageDownloader);

    Q_UNUSED(metadata)

    QNetworkRequest request(url);
    return d->networkAccessManager->get(request);
}

QString VKContactImageDownloader::outputFile(const QString &url, const QVariantMap &data,
                                             const QString &mimeType) const
{
    Q_UNUSED(mimeType); // TODO: use
    return staticOutputFile(data.value(IMAGE_DOWNLOADER_IDENTIFIER_KEY).toString(), url);
}
