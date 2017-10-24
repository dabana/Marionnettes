import pywinusb.hid as hid
from time import sleep
import time
import serial

def list_devices():
    all_devices = hid.HidDeviceFilter().get_devices()
    for a in all_devices:
        print(a)


def show_specific_device(target_vendor_id, target_product_id):
    target = hid.HidDeviceFilter(vendor_id=target_vendor_id, product_id=target_product_id)
    allitems = target.get_devices()
    device = allitems[0]
    #print(device)
    return device

lr0 = '0'
ud0 = '0'
YBAXstr0 = '0000'
RLstr0 = '00'
SrtSltstr0 = '00'

high_serial_str = ['ddh', 'dch', 'dbh', 'd9h']
low_serial_str = ['ddl', 'dcl', 'dbl', 'd9l']
i = 0
sleeptime = 0.1


def send_direction(var, var0, string):
    global ser
    try:
        print('try ...')
        ser.write(string.encode())
    except:
        print('failed somehow ...')
        ser = serial.Serial('COM3', 9600)
        pass
    sleep(sleeptime)
    var0 = var
    return var0


def send_buttons(var, var0):
    global high_serial_str, low_serial_str

    print('a button was pressed or released')
    string = '4'
    i = 0
    for x in var:
        if x == '1':
            string += high_serial_str[i]
        elif x == '0':
            string += low_serial_str[i]
        i += 1
    print('to print: ' + string)
    ser.write(string.encode())
    sleep(sleeptime)
    var0 = var
    return var0


def sample_handler(data):
    global lr0, ud0, YBAXstr0, RLstr0, SrtSltstr0, stringin, stringout,i
    # t0 = time.time()
    lr, ud, YBAXstr, RLstr, SrtSltstr = parse_data(data)
    #deltat = (time.time() - t0)
    #print('Up/down: ' + lr + ', Left/Right: ' + ud + ', YBAX string: ' + YBAXstr + ', RL string: ' + RLstr + ', SrtSlt string:' + SrtSltstr)
    #print('Took %.15f seconds' % deltat)

    #Handle directions
    if lr == '1' and lr != lr0:
        if i < 9:
            i += 1
            lr0 = send_direction(lr, lr0, '1sah' + str(i))
        print('going right: ' + str(i))
    elif lr == '-1' and lr != lr0:
        if i > 0:
            i -= 1
            lr0 = send_direction(lr, lr0, '1sah' + str(i))
        print('going left')
    elif lr == '0' and lr != lr0:
        lr0 = send_direction(lr, lr0, '1sal' + str(i))
        lr0 = send_direction(lr, lr0, '1sal' + str(i))
    if ud == '1' and ud != ud0:
        ud0 = send_direction(ud, ud0, '1sahh')
        print('going up')
    elif ud == '-1' and ud != ud0:
        ud0 = send_direction(ud, ud0, '1sahl')
        print('going down')
    elif ud == '0' and ud != ud0:
        ud0 = send_direction(ud, ud0, '1sall')
        ud0 = send_direction(ud, ud0, '1sall')

    #Handle Y,A,B,X buttons
    if YBAXstr != YBAXstr0:
        YBAXstr0 = send_buttons(YBAXstr, YBAXstr0)


def parse_data(data):

    trimmed_data = data[-5:-1]

    #extract directions
    if trimmed_data[1] == 0:
        ud = '-1' #down
    elif trimmed_data[1] == 255:
        ud = '1' #up
    else:
        ud = '0' #center
    if trimmed_data[0] == 0:
        lr = '-1' #left
    elif trimmed_data[0] == 255:
        lr = '1' #right
    else:
        lr = '0'

    #extract A, B, X, Y buttons
    # [Y, B, A, X]
    YBAXstr = bin(trimmed_data[2])[2:].zfill(8)
    YBAXstr = YBAXstr[:4]

    #extract L, R buttons
    # [R, L]
    RLstr = bin(trimmed_data[3])[2:].zfill(8)
    RLstr = RLstr[-2:]

    #extract start, select buttons
    # [Start, Select]
    SrtSltstr = bin(trimmed_data[3])[2:].zfill(8)
    SrtSltstr = SrtSltstr[2:4]

    #print('Up/down: ' + lr + ', Left/Right: ' + ud + ', YBAX string: ' + YBAXstr + ', RL string: ' + RLstr + ', SrtSlt string:' + SrtSltstr)
    return lr, ud, YBAXstr, RLstr, SrtSltstr


def get_data(device):
    device.open()
    device.set_raw_data_handler(sample_handler)
    while device.is_plugged():
        pass# just keep the device opened to receive events
        #sleep(sleeptime)
    return

list_devices()
vID = 0x0079
pID = 0x0011
device = show_specific_device(vID, pID)

with serial.Serial('COM3', 9600) as ser:
    get_data(device)

