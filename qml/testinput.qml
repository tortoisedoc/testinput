import QtQuick 2.0
import Sailfish.Silica 1.0

ApplicationWindow{
    anchors.fill:parent;
    MouseArea{
        anchors.fill:parent;
        onClicked: {
            console.log(" WINDOW CLICKED ");
        }
    }
    Rectangle{
        width:200;
        height:900;


        ListModel {
            id:my_model;
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }
        }
        ListView{
            anchors.fill: parent;
            model:my_model;
            delegate: Text {
                text: name + ": " + number
                height:80;
            }
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                    console.log(" LISTVIEW CLICKED ");
                }
            }
        }
    }
}

