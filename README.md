# BlueRCCar
BlueRCCar is a Bluetooth RC Car driver controler solution replacing standard radio RC Car equiped with HT8A978 radio receiver, by a Bluetooth 3.0 interface. 
The addition of Bluetooth on the RC Car make it compatible with most of the SmartPhones on the market.

The BlueRCCar système has been mounted on a Nikko Lazer 3.

![Nikko Lazer 3](/Pictures/NikkoLazer3.jpg "Nikko Lazer 3")

# Device Usage
Thsystem make the RC Car addressable via Bluetooth through an SPP profile using a really simplistic bidirectional protocol.

## Commands
The protocol is composed of Ascii commands that have the following meaning :

       Command      | Value |     |        Command      | Value 
------------------- | ----: | --- | ------------------- | ----:
Forward             | F     |     | Extra ON            | X
Backward            | B     |     | Extra OFF           | x
Left                | L     |     | Speed 0             | 0
Right               | R     |     | Speed 10            | 1
Forward Left        | G     |     | Speed 20            | 2
Forward Right       | I     |     | Speed 30            | 3
Backward Left       | H     |     | Speed 40            | 4
Backward Right      | J     |     | Speed 50            | 5
Stop                | S     |     | Speed 60            | 6
Front Lights ON     | W     |     | Speed 70            | 7
Front Lights OFF    | w     |     | Speed 80            | 8
Rear Lights ON      | U     |     | Speed 90            | 9
Rear Lights OFF     | u     |     | Speed 100           | q
Horn ON             | V     |     | Stop All            | D
Horn OFF            | v     |     |                     | 

# Bluetooht RC Android application
The supported protocol is compatbile with an existing Android application called **Arduino Bluetooth RC Car** developped by 'Andi.Co'. It is a free application and working on Android 2.3.3 and above.

## User Interface
![Bluetooht RC Interface](/Pictures/BluetoothRCAppInterface.png "Bluetooth RC Interface")


## Application Configuration


# Building the Hardware
The hardware is minimalistic as

# Building the Software
The ATtiny 85 is a really cool Micro Controller that have 8 KB of Flash and 512 B of RAM to run any kind of C or C++ software. This gives some space to run a simple software and for this reason some optimization are required.
The project has been developed in C++ (C++11) in order to reuse and give more flexibility in case of development of new features. It is required to use the VisualMicro extension for Visual Studio 2015 in order to build the project.

## Tools
Before starting some tools are required :

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* Visual Studio 2015 Community Edition (and other flavors)
* [VisualMicro](http://www.visualmicro.com/) a Visual Studio plugin for Arduino development
* USBTinyISP programer

Install Visual Studio 2015, and make sure to select the support for C++ (Visual C++) during installation.

Install the Arduino IDE application, and launch the application. You first need to add the support of the ATtiny familly as by default only Arduino based platforms are supported. From the File menu, select the Preferences submenu, and then find the “Additional Boards Manager URLs” field near the bottom of the dialog. Add the following url : https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json
You can then validate and close the preferences dialog box. Then from the Tools menu you have to :

* Select the Board entry and choose **Board Manager** to add ATtiny board support.
* Select **ATtiny** as Board
* Select **ATtiny85** as Processor
* Select **16MHz (Internal)** as Clock or **8MHz (Internal)** as Clock
* Select **USBtinyISP** as Programmer

## Project Dependencies
The project depends on the following libraries :

* **SoftwareSerial** by Peter Lerup revision 1.0.0
* **TinywireM** by Adafruit

In oder to be able to build the software all the dependencies need to be installed as following from Arduino IDE application :
* From the **Sketch** menu select the **Include Library**
* Select **Manage Libaries ...** from the list
* Search the library name using the search area 
* Install it using the **install** button.

## VisualMicro configuration

Close the **Arduino IDE** application and install the Visual Micro plugin for Visual Studio.
Launch **Visual Studio** and open the BlinkyBike.sln from the project folders.
On first usage of Visual Micro, you have to configure the various parameters of the plugin.

* Select the version of the IDE you select
* Enter the path to the tool installation folder

Then validate the configuration window and access the Visual Studio IDE. From vMicro menu :

* Select **ATtiny w/ ATtiny85** as Board
* Select **Internal 16MHz** or **Internal 8MHz** as Option2 (based on the Fuse configuration applied under Arduino IDE
* Select **USBtinyISP** as Programmer

The development environment is now ready for building and flashing.

## Compilation
The source code compiles in Visual Studio 2015 using the VisualMicro plugin and Arduino IDE (cf Tools chapter for installation details).
To compile the project you have to :

* Open the BlueRCCar\BlueRCCar.sln solution file
* From Visual Studio, select **Build** menu and choose **Configuration Manager** entry
* From the Configuration Manager window, select **Release** in the **Active solution confgiuration** drop box
* Click on the Close button to close the Configuration Manager window
* From **Build** menu select **Build Solution** entry
* Wait few seconds (usualy less than 30 seconds)
* Ensure that the last output from the Output window is : *Program size: 5,476 bytes (used 67% of a 8,192 byte maximum) (17.83 secs)* (values may vary)

Then you are ready to program your ATtiny 85.

## Programming
The ATtiny 85 micro controller can be programmed using the USBTinyISP programmer. The programmer is visible through a serial com port. You need to identify the associate port index (using Windows Device Manager) in order configure the Visual Micro plugin. 

![USB Tiny ISP](/Pictures/USBtinyISP.jpg "USB Tiny ISP")

You need to wire the programmer as following:

![USB Tiny ISP with ATtiny85](/Pictures/USBtinyISP_attiny85_connection.png "USB Tiny ISP with ATtiny85")

# Assembling


# Revision History
## V1.0 - 2017-xx-xx
* 

