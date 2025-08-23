#ifndef TASK_HPP
#define TASK_HPP

#include <QObject>
#include <QString>
#include <QDateTime>
#include <optional>

class Task : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned int m_id READ getId WRITE setId NOTIFY idChanged)
	Q_PROPERTY(QString m_title READ getTitle WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString m_description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(bool m_completed READ isCompleted WRITE setCompleted NOTIFY completedChanged)
	Q_PROPERTY(QDateTime m_createdAt READ getCreatedAt CONSTANT)

private:
	unsigned int m_id{};
	QString m_title{};
	QString m_description{};
	bool m_completed{};
	QDateTime m_createdAt{QDateTime::currentDateTime()};
	QDateTime m_startedAt{QDateTime::currentDateTime()};
	QDateTime m_completedAt{};

public:
	Task(QObject *parent = nullptr)
		: QObject(parent) {}

	Task(const QString &t, const QString &d, bool c = false, QObject *parent = nullptr)
		: QObject(parent), m_title(t), m_description(d), m_completed(c) {}

	Task(unsigned int i, const QString &t, const QString &d, bool c, QObject *parent = nullptr)
		: QObject(parent), m_id(i), m_title(t), m_description(d), m_completed(c) {}

	unsigned int getId() const { return m_id; }
	const QString &getTitle() const { return m_title; }
	const QString &getDescription() const { return m_description; }
	bool isCompleted() const { return m_completed; }
	QDateTime getCreatedAt() const { return m_createdAt; }

	void setId(unsigned int i)
	{
		if (m_id != i)
		{
			m_id = i;
			emit idChanged();
		}
	}
	void setTitle(const QString &t)
	{
		if (m_title != t)
		{
			m_title = t;
			emit titleChanged();
		}
	}
	void setDescription(const QString &d)
	{
		if (m_description != d)
		{
			m_description = d;
			emit descriptionChanged();
		}
	}
	void setCompleted(bool c)
	{
		if (m_completed != c)
		{
			m_completed = c;
			emit completedChanged();
		}
	}

	Task *clone(QObject *parent = nullptr) const
	{
		Task *t = new Task(parent);
		t->setId(m_id);
		t->setTitle(m_title);
		t->setDescription(m_description);
		t->setCompleted(m_completed);
		return t;
	}

signals:
	void idChanged();
	void titleChanged();
	void descriptionChanged();
	void completedChanged();
};

#endif
