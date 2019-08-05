/**
*
* @Name : MongoSample.C
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-06
* @Released under : https://github.com/BaseMax/MongoCSample/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/MongoCSample
*
**/
#include <mongoc/mongoc.h>
int main() {
	const char *uri_string = "mongodb://localhost:27017";
	mongoc_uri_t *uri;
	mongoc_client_t *client;
	mongoc_database_t *database;
	mongoc_collection_t *collection;
	bson_t *command, reply, *insert;
	bson_error_t error;
	char *str;
	bool retval;
	mongoc_init ();
	uri = mongoc_uri_new_with_error (uri_string, &error);
	if (!uri) {
		fprintf (stderr, "failed to parse URI: %s\n" "error message:       %s\n", uri_string, error.message);
		return EXIT_FAILURE;
	}
	client = mongoc_client_new_from_uri (uri);
	if (!client) {
		return EXIT_FAILURE;
	}
	mongoc_client_set_appname (client, "connect-example");
	database = mongoc_client_get_database (client, "db_name");
	collection = mongoc_client_get_collection (client, "db_name", "coll_name");
   	return 0;
}
