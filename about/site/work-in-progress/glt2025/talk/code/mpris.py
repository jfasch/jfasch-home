from sdbus import DbusInterfaceCommon, dbus_method

class MPRISPlayer(DbusInterfaceCommon,
                  interface_name='org.mpris.MediaPlayer2.Player'):

    @dbus_method()
    def PlayPause(self):
        raise NotImplementedError

class MPRISApp(DbusInterfaceCommon,
               interface_name='org.mpris.MediaPlayer2'):

    @dbus_method()
    def Quit(self):
        raise NotImplementedError
