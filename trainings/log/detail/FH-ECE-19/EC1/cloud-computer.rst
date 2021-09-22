Cloud Computer, SSH Login
=========================

.. contents::
   :local:

Machine, Logins
---------------

* A *Debian machine* has been setup somewhere on The Internet, IP
  address ``34.107.39.200``.
* *Logins* exist for the following users

  (not disclosed publically)

  Passwords are not published here for obvious reasons; those are
  communicated in one of the first lessons.

Login via Secure Shell (SSH)
----------------------------

* From a Linux system, use the ``ssh`` program (substitute my username
  with yours)

  .. code-block:: console
  
     $ ssh faschingbauer.joerg@34.107.39.200
     The authenticity of host '34.107.39.200 (34.107.39.200)' can't be established.
     ECDSA key fingerprint is SHA256:/in22o4VCD400X0bb4FlCb5/vQnrvKvOirgfqq6maPo.
     Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
     Warning: Permanently added '34.107.39.200' (ECDSA) to the list of known hosts.
     faschingbauer.joerg@34.107.39.200's password: 
     Linux fh-ece-19 4.19.0-14-cloud-amd64 #1 SMP Debian 4.19.171-2 (2021-01-30) x86_64
     
     The programs included with the Debian GNU/Linux system are free software;
     the exact distribution terms for each program are described in the
     individual files in /usr/share/doc/*/copyright.
     
     Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
     permitted by applicable law.
     Last login: Sat Feb 27 15:04:09 2021 from 77.119.129.226
     faschingbauer.joerg@fh-ece-19:~$ 

* From a Windows system, use `PuTTY <https://www.putty.org/>`__ to do
  the same.

  .. raw:: html

     <iframe
         width="560" 
	 height="315" 
	 src="https://www.youtube.com/embed/umFEuHWJW3w" 
	 frameborder="0" 
	 allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	 allowfullscreen>
     </iframe>
    
