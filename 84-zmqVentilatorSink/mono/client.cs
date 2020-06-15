using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Threading;
using System.Text;
using ZeroMQ;

namespace Examples {
static partial class Program {
	public static void sender(){
		using(var context=new ZContext()) using(var sockSend=new ZSocket(context, ZSocketType.PUSH)) {
			Console.WriteLine("Sender: tcp://127.0.0.1:5558");
			sockSend.Connect("tcp://127.0.0.1:5558");
			while(true) {
				int value=new Random().Next(10, 100);
				string ss="{\"command\":\"ack\",\"options\":{\"ack\":\"true\"}}";
				byte[] bytes=Encoding.ASCII.GetBytes(ss);
				sockSend.Send(bytes, 0, bytes.Length);
				Thread.Sleep(1000);
			}
		}
	}
	public static void receiver(){
		using(var context=new ZContext()) using(var sockRcpt=new ZSocket(context, ZSocketType.SUB)) {
			Console.WriteLine("Receiver: tcp://127.0.0.1:5557");
			sockRcpt.Connect("tcp://127.0.0.1:5557");
			sockRcpt.Subscribe("");
			while(true) {
				using(var replyFrame=sockRcpt.ReceiveFrame()) {
					string reply=replyFrame.ReadString();
					Console.WriteLine("RECEIVED: "+reply);
				}
			}
		}
	}
	public static void Main(string[] args) {
		Thread t=new Thread(new ThreadStart(receiver));
		t.Start();
		Thread k=new Thread(new ThreadStart(sender));
		k.Start();
		t.Join();
		k.Join();
	}
} }
