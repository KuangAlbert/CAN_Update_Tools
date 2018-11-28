<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="18008000">
	<Item Name="我的电脑" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="build status string.vi" Type="VI" URL="../VI/build status string.vi"/>
		<Item Name="closeneodevices.vi" Type="VI" URL="../VI/closeneodevices.vi"/>
		<Item Name="const_cluster_firesetting.vi" Type="VI" URL="../VI/const_cluster_firesetting.vi"/>
		<Item Name="const_cluster_spymessage.vi" Type="VI" URL="../VI/const_cluster_spymessage.vi"/>
		<Item Name="const_cluster_svcan3settings.vi" Type="VI" URL="../VI/const_cluster_svcan3settings.vi"/>
		<Item Name="ctl firesetting.ctl" Type="VI" URL="../VI/ctl firesetting.ctl"/>
		<Item Name="ctl networkid.ctl" Type="VI" URL="../VI/ctl networkid.ctl"/>
		<Item Name="ctl spy protocols.ctl" Type="VI" URL="../VI/ctl spy protocols.ctl"/>
		<Item Name="ctl spymessage.ctl" Type="VI" URL="../VI/ctl spymessage.ctl"/>
		<Item Name="ctl StatusBitfield.ctl" Type="VI" URL="../VI/ctl StatusBitfield.ctl"/>
		<Item Name="ctl svcansetting.ctl" Type="VI" URL="../VI/ctl svcansetting.ctl"/>
		<Item Name="findneodevices.vi" Type="VI" URL="../VI/findneodevices.vi"/>
		<Item Name="forumlate message write.vi" Type="VI" URL="../VI/forumlate message write.vi"/>
		<Item Name="getconfiguration.vi" Type="VI" URL="../VI/getconfiguration.vi"/>
		<Item Name="getdllversion.vi" Type="VI" URL="../VI/getdllversion.vi"/>
		<Item Name="GetErrorInfo.vi" Type="VI" URL="../VI/GetErrorInfo.vi"/>
		<Item Name="geterrormessages.vi" Type="VI" URL="../VI/geterrormessages.vi"/>
		<Item Name="getfiresettings.vi" Type="VI" URL="../VI/getfiresettings.vi"/>
		<Item Name="getmessages.vi" Type="VI" URL="../VI/getmessages.vi"/>
		<Item Name="GetTimeStampForMsg.vi" Type="VI" URL="../VI/GetTimeStampForMsg.vi"/>
		<Item Name="getvcan3setting.vi" Type="VI" URL="../VI/getvcan3setting.vi"/>
		<Item Name="NEO VI Example.vi" Type="VI" URL="../VI/NEO VI Example.vi"/>
		<Item Name="openneodevice.vi" Type="VI" URL="../VI/openneodevice.vi"/>
		<Item Name="parse message read.vi" Type="VI" URL="../VI/parse message read.vi"/>
		<Item Name="sendconfiguration.vi" Type="VI" URL="../VI/sendconfiguration.vi"/>
		<Item Name="setbitrate.vi" Type="VI" URL="../VI/setbitrate.vi"/>
		<Item Name="setfiresettings.vi" Type="VI" URL="../VI/setfiresettings.vi"/>
		<Item Name="setvcan3setting.vi" Type="VI" URL="../VI/setvcan3setting.vi"/>
		<Item Name="transmit messages.vi" Type="VI" URL="../VI/transmit messages.vi"/>
		<Item Name="txmessages raw.vi" Type="VI" URL="../VI/txmessages raw.vi"/>
		<Item Name="依赖关系" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="icsneo40.dll" Type="Document" URL="../NEO VI Example/data/icsneo40.dll"/>
		</Item>
		<Item Name="程序生成规范" Type="Build"/>
	</Item>
</Project>
