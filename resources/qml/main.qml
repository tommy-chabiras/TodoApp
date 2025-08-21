import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick.Controls.Material 6.5
import QtQuick.Layouts 1.4

ApplicationWindow {
    visible: true
    width: 500
    height: 300
    title: "TodoApp"

    ListView {
        anchors.fill: parent
        model: taskManager

        delegate: Rectangle {
            id: rowRect
            height: 40
            width: 400

            color: index % 2 === 0 ? "#f0f0f0" : "#ffffff"
            border.color: "#cccccc"
            border.width: 1

            radius: 10
            anchors.horizontalCenter: parent.horizontalCenter

            MouseArea {
                hoverEnabled: true
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onEntered: parent.color = "#c7c2c2"
                onExited: parent.color = index % 2 === 0 ? "#f0f0f0" : "#ffffff"
            }

            RowLayout {
                id: rowContent
                anchors.fill: parent
                anchors.margins: 5
                spacing: 10

                Text {
                    text: (index + 1) + "."
                    font.bold: true
					Layout.fillHeight: true
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    text: model.title
					Layout.fillHeight: true
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    text: model.description
					Layout.fillHeight: true
                    verticalAlignment: Text.AlignVCenter
                }


                Item {
                    Layout.fillWidth: true
                }

                Button {
                    text: "Edit"
                    Layout.alignment: Qt.AlignVCenter
					Layout.fillHeight: true 
                    background: Rectangle {
                        color: "#b3b3b3"
                        radius: 10
                    }
                }

                Button {
                    text: "Remove"
                    Layout.alignment: Qt.AlignVCenter
					Layout.fillHeight: true 
                    background: Rectangle {
                        color: "#FF0000"
                        radius: 10
                    }
                }
            }
        }
    }
}
