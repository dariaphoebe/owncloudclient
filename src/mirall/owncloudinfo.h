/*
 * Copyright (C) by Klaas Freitag <freitag@kde.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef OWNCLOUDINFO_H
#define OWNCLOUDINFO_H

#include <QObject>
#include <QNetworkReply>

namespace Mirall
{

class ownCloudInfo : public QObject
{
  Q_OBJECT
public:
  explicit ownCloudInfo(QObject *parent = 0);

  bool isConfigured();

  QString configFile() const;
  QString url() const;
  QString user() const;
  QString password() const;

  void checkInstallation();

signals:
  void ownCloudInfoFound( const QString&,  const QString& );
  void noOwncloudFound();

public slots:

protected slots:
    void slotReplyFinished( QNetworkReply* );
    void slotReadyRead();
    void slotError( QNetworkReply::NetworkError );

private:
    QNetworkReply *_reply;
    QByteArray    _readBuffer;
};

};

#endif // OWNCLOUDINFO_H
