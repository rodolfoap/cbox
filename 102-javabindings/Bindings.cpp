#include <Bindings.hpp>
#include <iostream>

extern "C" {
/*
 * Class:     eu_acme_bindings_Bindings
 * Method:    cget
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_eu_acme_bindings_Bindings_cget
  (JNIEnv *, jobject anobject, jstring key){
	  std::cout<<key<<std::endl;
	  return key;
}

/*
 * Class:     eu_acme_bindings_ConfDealer
 * Method:    cset
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_eu_acme_bindings_Bindings_cset
  (JNIEnv *, jobject anobject, jstring key, jstring value){
	  std::cout<<key<<std::endl;
	  std::cout<<value<<std::endl;
}

}
