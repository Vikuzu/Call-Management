PROJECT_DIR=/home/shailaja
USER_TEXT_FILENAME=user.txt
CONTACTS_TEXT_FILENAME=contacts.txt
LAST_USER_ID=U004
LAST_CONTACT_ID=C005

class Settings {​​
static string PROJECT_DIR;
static string USER_TEXT_FILENAME;
static string CONTACTS_TEXT_FILENAME;
static string LAST_USER_ID;
static string LAST_CONTACT_ID;
static int MAX_NAME_SIZE = 25;
}​​
main()
{​​
ini_func();
}​​
void ini_func() {​​
read file setting.ini
line = "part1=part2"
if (part1 = "PROJECT_DIR")
Settings::PROJECT_DIR = part2;
//store other values
}​​
