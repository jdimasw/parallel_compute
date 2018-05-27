#include <json/json.h>
#include <stdio.h>

int main(){
char * string = "{\"name\":\"dimas\", \"age\":22}";
json_object *jobj = json_tokener_parse(string);
json_object *obj_age = json_object_object_get(jobj,"name");

const char *age_val = json_object_get_string(obj_age);
printf("%s\n", age_val);

return 0;
}
