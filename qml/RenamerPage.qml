import QtQuick 2.15
import QtQuick.Controls 2.15
import Hub 1.0

Page {
  id: renamer
  title: qsTr("Image Renamer")

  ColumnLayout {
    anchors.fill: parent; spacing: 16; padding: 16

    RowLayout {
      Button { text: qsTr("Select Folder") }
      Button { text: qsTr("Rename Selected") }
    }

    TableView {
      id: table
      Layout.fillWidth: true
      Layout.fillHeight: true
      model: FileTableModel { }    // to be implemented next
      TableViewColumn { role: "fileName"; title: qsTr("Filename") }
      TableViewColumn { role: "preview"; title: qsTr("Preview") }
    }
  }
}