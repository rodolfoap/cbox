package eu.acme.bindings;

import java.nio.file.FileSystems;

public class Bindings {
	private String filename;

	// Ensure library is only loaded once
	static {
		// Unix based
		System.load(FileSystems.getDefault().getPath("./build/libBindings.so").normalize().toAbsolutePath().toString());
	}

	public Bindings(String filename) {
		super();
		this.filename = filename;
	}

	private native String cget(String key);
	private native void cset(String key, String value);

	public String get(String key) {
		return cget(key);
	}
	public void set(String key, String value) {
		cset(key, value);
	}
	public static void main(String[] args) {
		Bindings bindings=new Bindings("config.yaml");
		System.out.println(bindings.cget("myvariable") + "\n");
	}
}
