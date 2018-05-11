/*
 * TextMessageFeaturePlugin.h - declaration of TextMessageFeature class
 *
 * Copyright (c) 2017-2018 Tobias Junghans <tobydox@veyon.io>
 *
 * This file is part of Veyon - http://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef TEXT_MESSAGE_FEATURE_PLUGIN_H
#define TEXT_MESSAGE_FEATURE_PLUGIN_H

#include "Feature.h"
#include "FeatureProviderInterface.h"

class TextMessageFeaturePlugin : public QObject, FeatureProviderInterface, PluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "io.veyon.Veyon.Plugins.FeatureProviderInterface")
	Q_INTERFACES(PluginInterface FeatureProviderInterface)
public:
	TextMessageFeaturePlugin( QObject* parent = nullptr );
	~TextMessageFeaturePlugin() override {}

	Plugin::Uid uid() const override
	{
		return QStringLiteral("8ae6668b-9c12-4b29-9bfc-ff89f6604164");
	}

	QVersionNumber version() const override
	{
		return QVersionNumber( 1, 0 );
	}

	QString name() const override
	{
		return QStringLiteral("TextMessage");
	}

	QString description() const override
	{
		return tr( "Send a message to a user" );
	}

	QString vendor() const override
	{
		return QStringLiteral("Veyon Community");
	}

	QString copyright() const override
	{
		return QStringLiteral("Tobias Junghans");
	}

	const FeatureList& featureList() const override;

	bool startFeature( VeyonMasterInterface& master, const Feature& feature,
					   const ComputerControlInterfaceList& computerControlInterfaces ) override;

	bool stopFeature( VeyonMasterInterface& master, const Feature& feature,
					  const ComputerControlInterfaceList& computerControlInterfaces ) override;

	bool handleFeatureMessage( VeyonMasterInterface& master, const FeatureMessage& message,
							   ComputerControlInterface::Pointer computerControlInterface ) override;

	bool handleFeatureMessage( VeyonServerInterface& server, const FeatureMessage& message ) override;

	bool handleFeatureMessage( VeyonWorkerInterface& worker, const FeatureMessage& message ) override;

private:
	enum Commands {
		ShowTextMessage
	};

	enum FeatureMessageArguments {
		MessageTextArgument,
		MessageIcon,
		FeatureMessageArgumentCount
	};

	Feature m_textMessageFeature;
	FeatureList m_features;

};

#endif // TEXT_MESSAGE_FEATURE_PLUGIN_H
