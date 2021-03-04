import java.util.StringTokenizer;
import org.zeromq.ZMQ;

public class Subscriber {
	public static void main(String[] args) {
		ZMQ.Context context = ZMQ.context(1);
		ZMQ.Socket subscriber = context.socket(ZMQ.SUB);
		subscriber.connect("tcp://localhost:5556");
		subscriber.subscribe("");

		int count;
		for (count = 0; count < 5; count++) {
			String string = subscriber.recvStr(0).trim();
			StringTokenizer sscanf = new StringTokenizer(string, " ");
			String json = sscanf.nextToken();
			System.out.println("SUB: Got message [" + count + "]: " + json);
		}
		subscriber.close();
		context.term();
	}
}
