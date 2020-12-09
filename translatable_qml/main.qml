import QtQuick 2.6
import QtQuick.Window 2.2
import Translator 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Repeater {
        anchors.fill: parent
        model: langModel
        delegate: Item {
            width: parent.width
            height: parent.height / 2
            y: index * height
            Text {
                anchors.centerIn: parent
                text: name
            }
            MouseArea {
                anchors.fill: parent
                onClicked: ts.setLanguage(lang)
            }
        }
    }
    ListModel {
        id: langModel
        ListElement {
            name: 'English'
            lang: 'en_US'
        }
        ListElement {
            name: 'Japanese'
            lang: 'ja_JP'
        }
    }
    Translator {
        id: ts
    }
}
