[33mcommit b4843eadce410a2a042ca9b555329f4d9ec2587b[m
Author: dabana <david.banville2712@gmail.com>
Date:   Tue Oct 24 10:33:38 2017 -0400

    just add --all damn it

[33mcommit 523c90b7cf11cf0f179a1728e9892304621f9a80[m
Author: dabana <david.banville2712@gmail.com>
Date:   Tue Oct 24 10:28:22 2017 -0400

    try to delete idea files

[33mcommit a3846bf8fe39af139ed0fb556af5a0a28b3213ff[m
Author: dabana <david.banville2712@gmail.com>
Date:   Tue Oct 24 08:40:22 2017 -0400

    add the arduino sketch in its folder

[33mcommit 17a37831be102ee33c81ca07a549e96b96059b84[m
Author: dabana <david.banville2712@gmail.com>
Date:   Tue Oct 24 07:37:44 2017 -0400

    add the arudino sketch to control pins remotely

[33mcommit 155599fdf599c8e4dc353294e721ac2a3ad41428[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 09:56:48 2017 -0400

    Got rid of the remanence by removing the print statements in the arduino code. also simplified the python code.

[33mcommit c54b49db951838fabd7cf5323a79e3d5151bc86d[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 09:29:37 2017 -0400

    add a 1 in front of every string for direction handling

[33mcommit ebf2e6852aa37a7c06f8ddc83135d48effe63652[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 09:27:20 2017 -0400

    played with the sleep time without succes then realize arrows do not work

[33mcommit 562e5f086488370e7154c04cac34d36a4e25119a[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 09:02:37 2017 -0400

    do some more stuff to get rid of remanence but can't

[33mcommit 09c17f222317a0fd5d3b2b759cdce2bdb9fe9c74[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 08:36:43 2017 -0400

    enabled sending strings larger than 4 but did not help remanence problem

[33mcommit 7687672cd03a137d52fc390b6a551c9ca36aa4b0[m
Author: dabana <david.banville2712@gmail.com>
Date:   Mon Oct 23 08:24:44 2017 -0400

    send multiple strings for XABY buttons. But does not help for the remanence problem.

[33mcommit bb2314a8d663a71085c07894e20eac7ef74cb807[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 20:26:32 2017 -0400

    improved responsivity of buttons handling

[33mcommit 3ba6d74998b54fdfbd76632b8dc856a72c4bf978[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 19:55:32 2017 -0400

    add support for up and down motion as well as X Y B A buttons

[33mcommit a882e60971225be03a5b60f5549b297b1efcb2f8[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 18:32:55 2017 -0400

    added a return of the zero variable in the send_command function

[33mcommit c10b045e0d473766b28d32d21904ce97d9223525[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 18:23:40 2017 -0400

    Did not find anyway to avoid the timed delay after writing command. out_waiting, outWaiting attribute/method did not work...

[33mcommit f683bb72e5df3879d21d45cc4c58f97f9c29ec2b[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 18:10:09 2017 -0400

    Trying to get rid of the sleep(0.1) between writing to serial tasks. One of the two LEDs stays on.

[33mcommit 293f3d3bdec6b78743e4991fc7afc79cd2e0af90[m
Author: dabana <david.banville2712@gmail.com>
Date:   Sun Oct 22 17:25:01 2017 -0400

    Got a simple application getting data from the HID game controller and sending commands over serial port
