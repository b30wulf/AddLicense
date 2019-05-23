#include "AddLicense.h"
#pragma warning(disable:4307)

using namespace std;
using namespace license;

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

char * NAME = "AddLicense";
char * VERSION = "0.1.1";
char * DESCRIPTION = "quick creation of license files.";
char * AUTHOR = "kamino";
char * WEBSITE = "https://github.com/kamino-space/AddLicense";

bool write_to_lic_file(string content) {
	ifstream licr("LICENSE");
	if (licr) {
		licr.close();
		cout << "The license file exists in the current directory. Overwrite? ([y]/n): ";
		char input;
		cin >> input;
		if (input == 'n' || input == 'N') {
			cout << "exit" << endl;
			return false;
		}
	}
	std::ofstream licw("LICENSE");
	if (!licw) {
		cout << "open file error." << endl;
		licw.close();
		return 0;
	}
	licw << content.c_str();
	licw.close();
	cout << "add finished. happy programming." << endl;;
	return true;
}

hash_t hash_(char const* str) {
	hash_t ret{ basis };
	while (*str) {
		ret ^= *str;
		ret *= prime;
		str++;
	}
	return ret;
}

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis) {
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

constexpr unsigned long long operator "" _hash(char const* p, size_t) {
	return hash_compile_time(p);
}

void usage() {
	cout << DESCRIPTION << "\n"
		"usage: addlic [licenses] or [options]\n"
		"demo:"
		"\taddlic mit\n"
		"\taddlic ls\n"
		"supported licenses:\n"
		"\tmit\tMIT License\n"
		"\tgpl\tGNU General Public License v3.0\n"
		"\tagpl\tGNU Affero General Public License v3.0\n"
		"\tlgpl\tGNU Lesser General Public License v3.0\n"
		"\tmoz\tMozilla Public License 2.0\n"
		"\tapache\tApache License 2.0\n"
		"\tunlic\tThe Unlicense\n"
		"supported options:\n"
		"\thelp\tshow usage message\n"
		"\tls\tlist all licenses\n"
		"\tselect\tfollow the information to choose\n"
		"\tversion\tshow version\n"
		"\tweb\tenter choosealicense website\n"
		"note: All the data came from the choosealicense website."
		<< endl;
}

void add(char*name) {
	switch (hash_(name))
	{
	case "mit"_hash:
		MIT mit;
		cout << mit.getName().c_str() << endl;
		cout << mit.getDescription().c_str() << endl;
		write_to_lic_file(mit.getContent());
		break;
	case "gpl"_hash:
		GPLv3 gpl;
		cout << gpl.getName().c_str() << endl;
		cout << gpl.getDescription().c_str() << endl;
		write_to_lic_file(gpl.getContent());
		break;
	case "agpl"_hash:
		AGPLv3 agpl;
		cout << agpl.getName().c_str() << endl;
		cout << agpl.getDescription().c_str() << endl;
		write_to_lic_file(agpl.getContent());
		break;
	case "lgpl"_hash:
		LGPLv3 lgpl;
		cout << lgpl.getName().c_str() << endl;
		cout << lgpl.getDescription().c_str() << endl;
		write_to_lic_file(lgpl.getContent());
		break;
	case "moz"_hash:
		Mozilla moz;
		cout << moz.getName().c_str() << endl;
		cout << moz.getDescription().c_str() << endl;
		write_to_lic_file(moz.getContent());
		break;
	case "apache"_hash:
		Apache apache;
		cout << apache.getName().c_str() << endl;
		cout << apache.getDescription().c_str() << endl;
		write_to_lic_file(apache.getContent());
		break;
	case "unlic"_hash:
		Unlicense unlic;
		cout << unlic.getName().c_str() << endl;
		cout << unlic.getDescription().c_str() << endl;
		write_to_lic_file(unlic.getContent());
		break;
	default:
		break;
	}
}

void ls() {
	cout <<
		"MIT License\n"
		"command: addlic mit\n"
		"A short and simple permissive license with conditions only requiring preservation of copyright and license notices. Licensed works, modifications, and larger works may be distributed under different terms and without source code.\n\n"
		"GNU General Public License v3.0\n"
		"command: addlic gpl\n"
		"Permissions of this strong copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.\n\n"
		"GNU Affero General Public License v3.0\n"
		"command: addlic agpl\n"
		"Permissions of this strongest copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights. When a modified version is used to provide a service over a network, the complete source code of the modified version must be made available.\n\n"
		"GNU Lesser General Public License v3.0\n"
		"command: addlic lgpl\n"
		"Permissions of this copyleft license are conditioned on making available complete source code of licensed works and modifications under the same license or the GNU GPLv3. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights. However, a larger work using the licensed work through interfaces provided by the licensed work may be distributed under different terms and without source code for the larger work.\n\n"
		"Mozilla Public License 2.0\n"
		"command: addlic moz\n"
		"Permissions of this weak copyleft license are conditioned on making available source code of licensed files and modifications of those files under the same license (or in certain cases, one of the GNU licenses). Copyright and license notices must be preserved. Contributors provide an express grant of patent rights. However, a larger work using the licensed work may be distributed under different terms and without source code for files added in the larger work.\n\n"
		"Apache License 2.0\n"
		"command: apache\n"
		"A permissive license whose main conditions require preservation of copyright and license notices. Contributors provide an express grant of patent rights. Licensed works, modifications, and larger works may be distributed under different terms and without source code.\n\n"
		"The Unlicense\n"
		"command: addlic unlic\n"
		"A license with no conditions whatsoever which dedicates works to the public domain. Unlicensed works, modifications, and larger works may be distributed under different terms and without source code."
		<< endl;
}

void select() {
	cout << "Do you want it simple and permissive? ([y]/n): " << endl;
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y') {
		cout << "Maybe you need a MIT License. Add it to this path? ([y]/n): " << endl;
		cin >> input;
		if (input == 'y' || input == 'Y') {
			add("mit");
			return;
		}
		else {
			cout << "exit." << endl;
			return;
		}
	}
	else {
		cout << "Do you care about sharing improvements? ([y]/n): " << endl;
		cin >> input;
		if (input == 'y' || input == 'Y') {
			cout << "Maybe you need a GNU GPLv3 License. Add it to this path? ([y]/n): " << endl;
			add("gpl");
			return;
		}
		else {
			cout << "Maybe you can get more information on https://choosealicense.com/." << endl;
			return;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		usage();
		return 0;
	}
	switch (hash_(argv[1]))
	{
	case "mit"_hash:
		add("mit");
		break;
	case "gpl"_hash:
		add("gpl");
		break;
	case "agpl"_hash:
		add("agpl");
		break;
	case "lgpl"_hash:
		add("lgpl");
		break;
	case "moz"_hash:
		add("moz");
		break;
	case "apache"_hash:
		add("apache");
		break;
	case "unlic"_hash:
		add("unlic");
		break;
	case "select"_hash:
		select();
		break;
	case "ls"_hash:
		ls();
		break;
	case "version"_hash:
		cout << VERSION << endl;
		break;
	case "web"_hash:
		cout << "please enter this website https://choosealicense.com/" << endl;
		break;
	case "help"_hash:
		usage();
		break;
	default:
		cout << "unknown command " << argv[1] << endl;
		usage();
		break;
	}
	return 0;
}
