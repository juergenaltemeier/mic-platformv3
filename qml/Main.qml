import QtQuick 2.15
import QtQuick.Controls 2.15
import Hub 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("mic-renamer-hub")

    RenamerPage {
        anchors.fill: parent
    }
}
