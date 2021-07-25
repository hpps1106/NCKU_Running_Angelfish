NCKU Running Angelfish
===
## Lane Departure Detection System
### Member
* 蕭學謙  N26104701@gs.ncku.edu.tw
* 徐韋凱  N26104890@gs.ncku.edu.tw
* 魏一帆 
### Introduction
Our work is lane departure detection system, combined with the popular AIoT applications in recent years. AI has been researched all over the world due to the enhancement of hardware in the past ten years, especially the Convolutional Neural Network. It is suitable for visual applications such as object detection and scene recognition. IoT has also developed rapidly in recent years, and related concepts such as the Internet of Vehicles are also becoming more popular. In the era of 5G, it is not difficult to connect the cloud computer to do lane departure detection. However, we emphasize the importance of edge computing and low power consumption. WE-I Plus's optimized computing architecture and ultra-low power consumption features can be used as an Always on Sensor at the front end, and wake up the system at the back end when a lane is detected to get ready for the departure detection. Because WE-I Plus can save power and reduce the load on the servers significantly, we believe that it will be a good device of lane departure detection system.
### System architecture
![](https://i.imgur.com/WmGmOSL.png)
### Hardware and Software Requirement
#### Required Hardware
* WE-I plus開發版
#### Required Software
* 序列埠傳輸終端，如Tera Term，以接受來自WE-I之訊息。
## User Manual
### Before Running This Application
* 測試時，需透過傳輸線將WE-I連結電腦，開啟TERA以查看板子資訊。如下圖。
  * ![](https://i.imgur.com/paRofnb.png)
* 實際應用時，傳輸資訊改以燈號顯示(未來可將此訊號做為不同模組的啟動訊號，像是方向盤、油門等)，須將板子安裝在車內(前方景色需清晰可見)，並須供給穩定電源提供至板子。

### Run This Application
* 按下Reset，程式和硬體及會如預期運作。在測試時，透過Tera Term，可以接收到如以下之資訊。
* ![](https://i.imgur.com/Iwc1UD7.png)
* 而實際應用時，由於看不到板子傳輸資訊，則以LED燈號替代之。
(綠燈：車道無偏；紅燈：車道偏移，請盡快回正！)
### Future outlook
* 在自駕車近日的蓬勃發展下，不容忽視的行車安全，以及邊緣運算的進步，都使得越來越多人關注著此項技術的發展。期望車道偵測輔助系統，能不再只是"輔助"。





