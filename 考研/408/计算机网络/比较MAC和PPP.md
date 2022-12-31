<h1><a name="t12"></a><a id="3PPPMAC_70"></a>3.PPP和MAC的不同点</h1>
<ul><li>使用范围不同 
  <ul><li>PPP属于广域网范畴</li><li>MAC是局域网（以太网）范畴</li></ul> </li><li>支持的网络结构不同 
  <ul><li>PPP支持的网络结构只能是点对点</li><li>MAC支持多点对多点</li></ul> </li><li>地址需求不同 
  <ul><li>PPP是点到点协议，逻辑上相连的就一台设备，因此不需要寻址 PPP协议通过自身的协商实现点到点的数据传输</li><li>MAC帧的前两个字段分别为6字节长的目的地址和源地址字段，用于寻址</li></ul> </li></ul>
  <h1><a name="t13"></a><a id="4PPPMAC_82"></a>4.PPP和MAC的相同点</h1>
  <ul><li>属于同一层概念 
  <ul><li>PPP与MAC都属于数据链路子层的概念</li></ul> </li><li>承载的数据相同 
  <ul><li>PPP帧与MAC帧都可以承载IP数据报packet</li></ul> </li></ul>
  <h1><a name="t14"></a><a id="5PPPMACPPPOEPoint_to_Point_Protocol_over_Ethernet_88"></a>5.PPP和MAC结合PPPOE（Point to Point Protocol over Ethernet）</h1>
  <ul><li>PPPoE 是为宽带上网的主机使用的链路层协议，这个协议将PPP帧再封装到以太网帧中（当然还要增加一些能够识别各用户的功能）</li><li>PPPoE 是PPP协议能够适应多种类型链路的一个典型例子</li></ul>
  