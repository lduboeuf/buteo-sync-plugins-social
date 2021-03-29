/****************************************************************************
 **
 ** Copyright (c) 2015 - 2021 Jolla Ltd.
 **
 ** This program/library is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public License
 ** version 2.1 as published by the Free Software Foundation.
 **
 ** This program/library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this program/library; if not, write to the Free
 ** Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 ** 02110-1301 USA
 **
 ****************************************************************************/

#include "dropboximagesplugin.h"
#include "dropboximagesyncadaptor.h"
#include "socialnetworksyncadaptor.h"

DropboxImagesPlugin::DropboxImagesPlugin(const QString& pluginName,
                             const Buteo::SyncProfile& profile,
                             Buteo::PluginCbInterface *callbackInterface)
    : SocialdButeoPlugin(pluginName, profile, callbackInterface,
                         QStringLiteral("dropbox"),
                         SocialNetworkSyncAdaptor::dataTypeName(SocialNetworkSyncAdaptor::Images))
{
}

DropboxImagesPlugin::~DropboxImagesPlugin()
{
}

SocialNetworkSyncAdaptor *DropboxImagesPlugin::createSocialNetworkSyncAdaptor()
{
    return new DropboxImageSyncAdaptor(this);
}

Buteo::ClientPlugin* DropboxImagesPluginLoader::createClientPlugin(
        const QString& pluginName,
        const Buteo::SyncProfile& profile,
        Buteo::PluginCbInterface* cbInterface)
{
    return new DropboxImagesPlugin(pluginName, profile, cbInterface);
}
