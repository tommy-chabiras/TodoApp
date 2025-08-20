import QtQuick 6.5
import QtQuick.Controls 6.5

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "TodoApp"

    ListView {
        anchors.fill: parent
        model: ListModel {
            // simple ListModel avoids unqualified access
            ListElement {
                title: "Task 1"
            }
            ListElement {
                title: "Task 2"
            }
        }
        delegate: Text {
            id: taskItem
            text: taskItem.title   // ✅ explicitly referencing this element
        }
    }
}
