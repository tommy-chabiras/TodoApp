import QtQuick 6.5
import QtQuick.Controls 6.5

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "TodoApp"

    ListModel {
        id: items

        ListElement {
            name: "Task 1"
        }
        ListElement {
            name: "Task 2"
        }
    }
    ListView {
        id: listview
        anchors.fill: parent
        model: items

        delegate: Label {
            required property string name
            text: name
        }
    }
}
