# service
（1）service用于在**后台**完成用户指定的操作。service分为两种：
- **startService**（启动）：当应用程序组件（如activity）调用startService()方法启动服务时，服务处于started状态。
	- tarted service（启动服务）是由**其他组件**调用startService()方法启动的，这导致服务的onStartCommand()方法被调用。当服务是started状态时，**其生命周期与启动它的组件无关**，并且可以在后台无限期运行，即使启动服务的组件已经被销
- **bindService**（绑定）：当应用程序组件调用bindService()方法绑定到服务时，服务处于bound状态。
	- 调用者与服务绑定在了一起，**调用者一旦退出，服务也就终止**，大有“不求同时生，必须同时死”的特点。