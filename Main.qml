import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 1024
    height: 640
    visible: true
    title: qsTr("BhssWS Yönetici")

    header: ToolBar {

        font.pointSize: 24
        RowLayout {
            anchors.fill: parent

            ToolButton {

                icon.width: 24
                icon.height: 24
                icon.color: "white"
                icon.source: drawer.state ? Qt.resolvedUrl("ui-icons/back.svg") : Qt.resolvedUrl("ui-icons/menu.svg")

                onClicked: {
                    if(!drawer.state){
                        drawer.open()
                        drawer.state = true
                    }
                    else{
                        drawer.close()
                        drawer.state = false
                    }
                }
            }
            Label {
                id: pageTitle
                text: stackView.currentItem.title
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                icon.width: 24
                icon.height: 24
                icon.color: "white"
                icon.source: Qt.resolvedUrl("ui-icons/settings.svg")
            }
        }
    }

    Drawer {
        id: drawer
        y: header.height
        width: window.width * 0.4
        height: window.height - header.height
        property bool state: false

        ListModel {
            id: menuModel
            ListElement {
                name : "Yeni Kart"
            }
            ListElement {
                name : "Yeni Kategori"
            }
            ListElement {
                name : "Yeni Alt Kategori"
            }
        }

        ListView {
            anchors.fill: parent
            model: menuModel

            delegate: ToolButton {
                width: parent.width

                property int buttonIndex: model.index

                Text {
                    text: name
                    verticalAlignment: Qt.AlignLeft
                    padding: 10
                    font.pointSize: 18
                }

                onClicked: {
                    switch(buttonIndex){
                    case 0:

                        break;
                    case 1:

                        break;
                    case 2:

                        break;
                    }
                    drawer.state = false
                    drawer.close()
                }
            }
        }

        onClosed: {
            state = false
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: newProduct
    }

    Component {
        id: newProduct
        NewProduct{}
    }

    footer: ToolBar {

    }
}
