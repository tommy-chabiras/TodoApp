#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("TodoApp");

    window.resize(300, 200);

	auto *layout = new QVBoxLayout(&window);

	QLabel *label = new QLabel("text");
    QPushButton *button  = new QPushButton("Add Task");

    // button.resize(200, 50);
    // button.show();

    layout->addWidget(label);
    layout->addWidget(button);

    window.setLayout(layout);
    window.show();

    // qDebug() << "Hello World!";

    // QLabel label("Hello, This is a GUI app");


    return app.exec();
}
