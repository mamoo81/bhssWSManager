import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.qmlmodels

Page {
    id: rootCategories

    font.pointSize: 18

    TableView {
        id: categoriesTableView
        anchors.fill: parent
        clip: true

        model: tableModel

        delegate: Rectangle {
            implicitWidth: 80
            implicitHeight: 30

            border.width: 1

            Text {
                text: display
                anchors.centerIn: parent
            }
        }
    }

    TableModel {
        id: tableModel
        TableModelColumn { display: "id" }
        TableModelColumn { display: "name" }
    }

    Connections {
        target: restApiHelper
        function onCategoriesReply(categories){

            var json = JSON.parse(categories)
            json.forEach(function(category){
                tableModel.insertRow(tableModel.rowCount, {"id": category["id"], "name": category["name"]})

            })
        }
    }

    Component.onCompleted: {
        restApiHelper.getCategories();
    }
}
