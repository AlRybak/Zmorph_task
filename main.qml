import QtQuick 2.12
import QtQuick.Window 2.12
import Zmorph.Interview 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Hello World")
    color: "dimgrey"

    GridLayout {
        Layout.alignment: Qt.AlignCenter
        anchors.fill: parent
        anchors.margins: 50
        columns: 4
        rowSpacing: 20
        columnSpacing: 20

        ListView {
            id: list
            model: gcodeFileController.gcodeFiles
            anchors.fill: parent
        }

        Repeater {
            model: gcodeFileController.gcodeFiles
            delegate: Rectangle {
                id: myRectangle
                Layout.alignment: Qt.AlignCenter
                //Layout.minimumWidth: 150
                //Layout.maximumWidth: 250
                //Layout.minimumHeight: 150
                //Layout.maximumHeight: 250
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "dimgrey"
                    Image {
                        anchors.fill: parent
                        source: thumbnailPath
                    }

                    MouseArea {
                        id: rectangleMouseArea
                        anchors.fill: parent
                        onPressed: {
                            list.currentIndex = index
                            parent.color = "mediumpurple"
                            showPath.text = "Ścieżka: " + thumbnailPath
                            showSize.text = "Rozmiar pliku: " + size + " bajtów"
                        }
                        onReleased: {
                            parent.color = "dimgrey"
                            showPath.text = null
                            showSize.text = null
                        }

                        cursorShape: Qt.PointingHandCursor
                    }
            }
        }

        Rectangle {
            id: blueRectangle
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "blue"
            Layout.columnSpan: 4
            Column {
                spacing: 10
                Text {
                    id: showPath
                    width: blueRectangle.width
                    wrapMode: Text.WordWrap
                }
                Text {
                    id: showSize
                    width: blueRectangle.width
                    wrapMode: Text.WordWrap
                }
            }
        }

    }

}



