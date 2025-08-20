#ifndef TASK_HPP
#define TASK_HPP

#include <QObject>
#include <QString>
#include <QDateTime>
#include <optional>

class Task : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned int id READ getId CONSTANT)
	Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(bool completed READ isCompleted WRITE setCompleted NOTIFY completedChanged)
	Q_PROPERTY(QDateTime createdAt READ getCreatedAt CONSTANT)

private:
	unsigned int id{};
	QString title{};
	QString description{};
	bool completed{};
	const QDateTime createdAt{QDateTime::currentDateTime()};
	QDateTime startedAt{QDateTime::currentDateTime()};
	QDateTime completedAt{};

public:
	Task(const QString &t, const QString &d, bool c = false, QObject *parent = nullptr)
		: QObject(parent), title(t), description(d), completed(c) {}

	Task(unsigned int i, const QString &t, const QString &d, bool c, QObject *parent = nullptr)
		: QObject(parent), id(i), title(t), description(d), completed(c) {}

	unsigned int getId() const { return id; }
	const QString &getTitle() const { return title; }
	const QString &getDescription() const { return description; }
	bool isCompleted() const { return completed; }
	QDateTime getCreatedAt() const { return createdAt; }

	void setTitle(const QString &t)
	{
		if (title != t)
		{
			title = t;
			emit titleChanged();
		}
	}
	void setDescription(const QString &d)
	{
		if (description != d)
		{
			description = d;
			emit descriptionChanged();
		}
	}
	void setCompleted(bool c)
	{
		if (completed != c)
		{
			completed = c;
			emit completedChanged();
		}
	}

signals:
	void titleChanged();
	void descriptionChanged();
	void completedChanged();
};

#endif
