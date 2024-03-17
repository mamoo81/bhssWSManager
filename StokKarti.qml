import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: rootStokKarti

    font.pointSize: 18

    title: "Stok Kartı"

    Connections {
        target: restApiHelper

        function onProductFind(product){
            idText.text = product.id
            barcodeTextField.text = product.barcode
            nameTextField.text = product.name
            fullnameTextField.text = product.fullname
            unitComboBox.currentIndex = product.unit
            priceTextField.text = Number(product.price).toFixed(2)
            categoryComboBox.currentIndex = product.category - 1
            producerComboBox.currentIndex = product.producer - 1 // index sıfıradan başladığı için veritabanında ki id numarasına denk gelsin diye -1 yapıyorum.
            kdvTextField.text = product.kdv
            otvTextField.text = product.otv
            productImage.source = product.imageHASH !== "" ? Qt.url(restApiHelper.imgBasatURL + product.imageHASH + ".png") : "ui-icons/product.svg"
        }

        function onUnitsFind(){
            unitComboBox.model = restApiHelper.units
        }

        function onProducersFind(){
            producerComboBox.model = restApiHelper.producers
        }

        function onCategoriesFind(){
            categoryComboBox.model = restApiHelper.categoriesANDsubcategories
        }
    }

    ListModel {
        id: subcategoriesModel
    }

    RowLayout {
        id: productSearchBar
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 2

        Text {
            text: "Barkod"
        }

        TextField {
            id: searchTextField
            Layout.fillWidth: true
            implicitHeight: 40
            inputMethodHints: Qt.ImhDigitsOnly

            onAccepted: {
                searchButton.clicked()
                Qt.inputMethod.hide()
            }

            Image {

                id: removeTextButton
                width: 32
                height: 32
                anchors {
                    right: parent.right
                    verticalCenter: parent.verticalCenter
                }

                visible: searchTextField.text.length > 0
                source: "ui-icons/backspace.svg"

                sourceSize {
                    width : 16
                    height: 16
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        searchTextField.clear()
                    }
                }
            }
        }

        Button {
            id: searchButton
            width: 50
            text: "Ara"

            onClicked: {
                restApiHelper.getProduct(searchTextField.text)
                searchTextField.clear()
            }
        }
    }

    GroupBox {
        anchors.top: productSearchBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: parent.height - productSearchBar.height
        anchors.margins: 2

        title: "Kart bilgileri"

        Flickable {
            width: parent.width
            height: parent.height
            contentHeight: columnLay.height
            flickableDirection: Flickable.VerticalFlick
            clip: true

            ColumnLayout {
                id: columnLay
                width: parent.width

                RowLayout {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignCenter

                    Image {
                        id: productImage
                        source: "ui-icons/product.svg"

                        sourceSize {
                            width : 128
                            height : 128
                        }
                    }
                }

                RowLayout {
                    width: parent.width

                    Text {
                        Layout.preferredWidth: 88
                        text: "ID"
                        font.pointSize: 16
                    }

                    Text {
                        id: idText
                        Layout.fillWidth: true
                        text: "123456789"
                        font.pointSize: 16
                    }
                }

                RowLayout {
                    width: parent.width

                    Text {
                        Layout.preferredWidth: 88
                        text: "Barkod"
                        font.pointSize: 16
                    }

                    TextField {
                        id: barcodeTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Adı"
                        font.pointSize: 16
                    }

                    TextField {
                        id: nameTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Tam adı"
                        font.pointSize: 16
                    }

                    TextField {
                        id: fullnameTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Birimi"
                        font.pointSize: 16
                    }

                    ComboBox {
                        id: unitComboBox
                        Layout.fillWidth: true
                        implicitHeight: 50

                        model: restApiHelper.units

                        delegate: ItemDelegate {
                            width: parent.width


                            contentItem: Text {
                                text: unitComboBox.model[index].name
                            }
                        }
                        displayText: unitComboBox.model[currentIndex].name
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Satış fiyatı"
                        font.pointSize: 16
                    }

                    TextField {
                        id: priceTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Kategorisi"
                        font.pointSize: 16
                    }

                    ComboBox {
                        id: categoryComboBox
                        Layout.fillWidth: true
                        implicitHeight: 50

                        model: restApiHelper.categoriesANDsubcategories

                        delegate: ItemDelegate {
                            width: parent.width
                            text: categoryComboBox.model[index].name

                            contentItem: Text {
                                text: categoryComboBox.model[index].name
                            }
                        }
                        displayText: categoryComboBox.model[currentIndex].name

                        onCurrentIndexChanged: {
                            var categories = restApiHelper.categoriesANDsubcategories
                            var subcategories = categories[currentIndex].subCategories

                            if(subcategories.length > 0){
                                subcategoryComboBox.model = subcategories
                            }
                            else{
                                subcategoryComboBox.model = []
                                subcategoryComboBox.currentIndex = -1
                            }
                        }
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Alt kategorisi"
                        font.pointSize: 16
                    }

                    ComboBox {
                        id: subcategoryComboBox
                        Layout.fillWidth: true
                        implicitHeight: 50

                        // model: subcategoriesModel

                        delegate: ItemDelegate {
                            width: parent.width
                            text: subcategoryComboBox.model[index].name

                            contentItem: Text {
                                text: subcategoryComboBox.model[index].name
                            }
                        }

                        displayText: subcategoryComboBox.model[currentIndex].name
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "KDV"
                        font.pointSize: 16
                    }

                    TextField {
                        id: kdvTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "OTV"
                        font.pointSize: 16
                    }

                    TextField {
                        id: otvTextField
                        Layout.fillWidth: true
                        implicitHeight: 40
                    }
                }

                RowLayout {

                    width: parent.width
                    Text {
                        Layout.preferredWidth: 88
                        text: "Üretici"
                        font.pointSize: 16
                    }

                    ComboBox {
                        id: producerComboBox
                        Layout.fillWidth: true
                        implicitHeight: 50

                        model: restApiHelper.producers

                        delegate: ItemDelegate {
                            width: parent.width
                            text: producerComboBox.model[index].id

                            contentItem: Text {
                                text: producerComboBox.model[index].name
                            }
                        }
                        displayText: producerComboBox.model[currentIndex].name
                    }
                }
            }
        }
    }
}
