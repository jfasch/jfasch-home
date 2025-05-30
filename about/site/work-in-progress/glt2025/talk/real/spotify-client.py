#!/usr/bin/env python3

from mpris import MPRISPlayer, MPRISApp
import sdbus

spotify_app_client = MPRISApp(
    bus = sdbus.sd_bus_open_user(),
    service_name = 'org.mpris.MediaPlayer2.spotify',
    object_path = '/org/mpris/MediaPlayer2')

spotify_app_client.Quit()
