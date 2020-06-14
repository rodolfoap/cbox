using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Threading;

using ZeroMQ;

namespace Examples {
static partial class Program {
	public static void sender(){
		while(true) {
			Console.WriteLine("T...");
			Thread.Sleep(1000);
		}
	}
	public static void Main(string[] args) {
		Thread t=new Thread(new ThreadStart(sender));
		t.Start();
		using(var context=new ZContext()) using(var subscriber=new ZSocket(context, ZSocketType.SUB)) {
			Console.WriteLine("Connecting to tcp://127.0.0.1:5557...");
			subscriber.Connect("tcp://127.0.0.1:5557");
			subscriber.Subscribe("");
			while(true) {
				using(var replyFrame=subscriber.ReceiveFrame()) {
					string reply=replyFrame.ReadString();
					Console.WriteLine(reply);
				}
			}
		}
	}
} }
