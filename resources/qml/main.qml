import QtQuick 6.5
import QtQuick.Controls 6.5

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "TodoApp"

    ListView {
        anchors.fill: parent
        model: taskManager

        delegate: Rectangle {
            width: 250
            height: 40
            color: index % 2 === 0 ? "#f0f0f0" : "#ffffff"
            border.color: "#cccccc"
            border.width: 1

            radius: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Row {

                anchors.fill: parent
                anchors.margins: 5
                spacing: 10

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: (index + 1) + "."    // Numbering starts from 1
                    font.bold: true
                }

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: model.title
                }

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: model.description
                }
            }
            MouseArea {
                hoverEnabled: true
                anchors.fill: parent
				cursorShape: Qt.PointingHandCursor
                onEntered: parent.color = "#c7c2c2"
                onExited: parent.color = index % 2 === 0 ? "#f0f0f0" : "#ffffff"
            }
        }
    }

    Button {
        text: "Add Task"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: taskManager.addTask("New from QML", "test")
    }
}
