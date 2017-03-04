import QtQuick 2.2
import Sailfish.Silica 1.0

Dialog {
    property string jid
    property string name

    Column {
        width: parent.width

        DialogHeader {
            id: header
            title: "Add Contact"
        }

        TextField {
            id: jidField
            width: parent.width
            placeholderText: "id@domain.org"
            label: "Jid"
        }

        TextField {
            id: nameField
            width: parent.width
            placeholderText: "Name"
            label: "NickName"
        }
    }

    onDone: {
        if (result == DialogResult.Accepted) {
            jid = jidField.text
            name = nameField.text

            console.log("new contact: " + jid + ", " + name)
            shmoose.rosterController.addContact(jid, name)
        }
    }
}