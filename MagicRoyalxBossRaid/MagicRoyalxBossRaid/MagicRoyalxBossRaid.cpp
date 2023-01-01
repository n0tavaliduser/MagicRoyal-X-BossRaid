// https://github.com/n0tavaliduser/MagicRoyal-X-BossRaid

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

// Class Player START Here
class Player {
public:
	// Constructor
	Player();

	// Method Setter
	void setUsername(string username);
	void setHeroname(string heroname);
	void setHealthCapacity(int healthCapacity);
	void setHealth(int health);
	void setDefendCapacity(int defendCapacity);
	void setDefend(int defend);
	void setDemage(int demage);
	void setBlessing(string blessing);
	void setSkill(string skill);
	void setSkillDemage(int demage);
	void setSkillCooldown(int cooldown);

	// Method Getter
	string getUsername();
	string getHeroname();
	int getHealthCapacity();
	int getHealth();
	int getDefendCapacity();
	int getDefend();
	int getDemage();
	vector<string> getBlessing();
	vector<string> getSkill();
	vector<int> getSkillDemage();
	vector<int> getSkillCooldown();
	string getSkillOf(int index);
	int getSkillDemageOf(int index);
	int getSkillCooldownOf(int index);

	// Additional Method
	void showPlayerDetail();
	void attackedWithBasic(int demage);
	void attackedWithSkill(int demage);
	void findBlessing();
	void removeBlessing(string blessingName);
	void healerEffect();
	void poisonEffect();
	int isBlessingOn(string blessingName);
protected:
	string username;
	string heroname;
	int healthCapacity;
	int health;
	int defendCapacity;
	int defend;
	int demage;
	vector<string> blessing;
	vector<string> skill;
	vector<int> skillDemage;
	vector<int> skillCooldown;
};
Player::Player() { Player::username = ""; Player::heroname = ""; }
// Setter
void Player::setUsername(string username) { Player::username = username; }
void Player::setHeroname(string heroname) { Player::heroname = heroname; }
void Player::setHealthCapacity(int healthCapacity) { Player::healthCapacity = healthCapacity; }
void Player::setHealth(int health) { Player::health = health; }
void Player::setDefendCapacity(int defendCapacity) { Player::defendCapacity = defendCapacity; }
void Player::setDefend(int defend) { Player::defend = defend; }
void Player::setDemage(int demage) { Player::demage = demage; }
void Player::setBlessing(string blessing) { Player::blessing.push_back(blessing); }
void Player::setSkill(string skill) { Player::skill.push_back(skill); }
void Player::setSkillDemage(int demage) { Player::skillDemage.push_back(demage); }
void Player::setSkillCooldown(int cooldown) { Player::skillCooldown.push_back(cooldown); }
// Getter
string Player::getUsername() { return Player::username; }
string Player::getHeroname() { return Player::heroname; }
int Player::getHealthCapacity() { return Player::healthCapacity; }
int Player::getHealth() { return Player::health; }
int Player::getDefendCapacity() { return Player::defendCapacity; }
int Player::getDefend() { return Player::defend; }
int Player::getDemage() { return Player::demage; }
vector<string> Player::getBlessing() { return Player::blessing; }
vector<string> Player::getSkill() { return Player::skill; }
vector<int> Player::getSkillDemage() { return Player::skillDemage; }
vector<int> Player::getSkillCooldown() { return Player::skillCooldown; }
string Player::getSkillOf(int index) { return Player::skill[index]; }
int Player::getSkillDemageOf(int index) { return Player::skillDemage[index]; }
int Player::getSkillCooldownOf(int index) { return Player::skillCooldown[index]; }

// Additional Method

// Method Show Player Detail START Here
void Player::showPlayerDetail() {
	cout << "==============================================" << endl;
	cout << "Username\t: " << Player::getUsername() << endl;
	cout << "Heroname\t: " << Player::getHeroname() << endl;
	cout << "Health.Cap\t: " << Player::getHealthCapacity() << endl;
	cout << "Health\t\t: " << Player::getHealth() << endl;
	cout << "Demage\t\t: " << Player::getDemage() << endl;
	cout << "Defend\t\t: " << Player::getDefend() << endl;
	cout << "Defend.Cap\t: " << Player::getDefendCapacity() << endl;
	cout << "==============================================" << endl;
	cout << "BLESSING : " << endl;
	for (int i = 0; i < Player::blessing.size(); i++) {
		cout << i + 1 << ". " << Player::blessing[i];
		if (Player::blessing[i] == "Healer") {
			cout << " (+2% HP from current max Cap.)";
		}
		else if (Player::blessing[i] == "Dominance") {
			cout << " (Up To 60% Defend Capacity)";
		}
		else if (Player::blessing[i] == "Silent") {
			cout << " (High Chance to silent enemy)";
		}
		else if (Player::blessing[i] == "Poison") {
			cout << " (-7% Enemy Health)";
		}
		cout << endl;
	}
	cout << "==============================================" << endl;
}
// Method Show Player Detail END Here


// Method Basic attack START Here
void Player:: attackedWithBasic(int demage) {
	cout << "Basic attack demage " << demage - (demage * Player::defend / 100) << "!!" << endl;
	Player::health = Player::health - (demage - (demage * Player::defend / 100));
}
// Method Basic attack END Here


// Method Basic attack START Here
void Player::attackedWithSkill(int demage) {
	Player::health = Player::health - demage;
}
// Method Basic attack END Here


// Method find random Blessing or Attribute START Here
void Player::findBlessing() {
	vector<string> blessingList = { "Dominance", "Silent", "Healer", "Poison" };

	int blessingIndex = rand() % 30;

	if (blessingIndex < blessingList.size()) {

		bool isOn = false;

		for (int i = 0; i < Player::getBlessing().size(); i++) {
			if (Player::blessing[i] == blessingList[blessingIndex]) {
				isOn = true;
			}
		}

		if (isOn) {
			cout << "Sudah memiliki blessing " << blessingList[blessingIndex] << endl;
		}
		else {
			cout << "Berhasil mendapatkan blessing " << blessingList[blessingIndex] << endl;
			Player::blessing.push_back(blessingList[blessingIndex]);
		}
	}
	else {
		int atr = rand() % 6;

		if (atr == 0) {
			cout << "Mendapatkan penambahan kapasitas darah +20" << endl;
			Player::healthCapacity = Player::healthCapacity + 20;
		}
		else if (atr == 1) {
			if ((Player::health + (Player::healthCapacity * 2 / 100)) >= Player::healthCapacity) {
				cout << "Mendapatkan penambahan darah, sekarang darah sudah maksimal" << endl;
				Player::health = Player::healthCapacity;
			}
			else {
				cout << "Mendapatkan penambahan darah sebesar 2% dari maksimal kapasitas" << endl;
				Player::health = Player::health + (Player::healthCapacity * 2 / 100);
			}
		}
		else if (atr == 2) {
			if (Player::defend + 1 >= Player::defendCapacity) {
				cout << "Mendapatkan penambahan kapasitas defend sebesar 1%" << endl;
				Player::defend = Player::defendCapacity;
			}
			else {
				cout << "Mendapatkan penambahan defend sebesar 1%" << endl;
				Player::defend = Player::defend + 1;
			}
		}
		else if (atr == 3) {
			cout << "Mendapatkan penambahan demage sebesar 5 poin" << endl;
			Player::demage = Player::demage + 5;
		}
		else {
			cout << "Gagal mendapatkan blessing maupun attribute :(" << endl;
		}
	}
}
// Method find random Blessing or Attribute END Here


// Method Remove Blessing START Here
void Player::removeBlessing(string blessingName) {
	int blessingIndex;
	for (int i = 0; i < Player::getBlessing().size(); i++) {
		if (Player::getBlessing()[i] == blessingName) {
			blessingIndex = i;
		}
	}

	vector<string>::iterator it;
	it = Player::blessing.begin();
	Player::blessing.erase(it + blessingIndex);
}
// Method Remove Blessing END Here


// Method Healer Effect START Here
void Player::healerEffect() {
	if (Player::getHealth() + (Player::getHealthCapacity() * 2 / 100) >= Player::getHealthCapacity()) {
		Player::health = Player::getHealthCapacity();
	}
	else {
		cout << "+" << Player::getHealthCapacity() * 2 / 100 << " Health from Healer !!!" << endl;
		Player::health = Player::health + (Player::getHealthCapacity() * 2 / 100);
	}
}
// Method Healer Effect END Here


// Method Poison Effect START Here
void Player::poisonEffect() {
	Player::health = Player::health - (Player::healthCapacity * 7 / 100);
}
// Method Poison Effect END Here


// Method Check Blessing On START Here
int Player::isBlessingOn(string blessingName) {
	for (int i = 0; i < Player::blessing.size(); i++) {
		if (Player::blessing[i] == blessingName) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
// Method Check Blessing On START Here

// Class Player END Here



// Class Hero START Here
class Hero : public Player {
public:
	// Constructor
	Hero();

	// Method Setter
	void setHerotype(string herotype);

	// Method Getter
	string getHerotype();
protected:
	string herotype;
};
Hero::Hero() : Player() { Hero::herotype = ""; }

void Hero::setHerotype(string herotype) { Hero::herotype = herotype; }
// Class Hero END Here




int main() {

	Hero player1;
	Hero player2;

	// Pembuatan atribut random
	srand(static_cast<unsigned int>(time(0)));

	// Setting Username Player 1 dan Player 2 START Here
	string usernameP1;
	string usernameP2;
	cout << "Masukan username player 1 : ";
	cin >> usernameP1;
	cout << "Masukan username player 2 : ";
	cin >> usernameP2;
	player1.setUsername(usernameP1);
	player2.setUsername(usernameP2);
	system("cls");
	// Setting Username Player 1 dan Player 2 END Here

	// Setting Hero Player 1 dan Player 2 START Here
	vector<string> herolist = { "Ragna", "Shadow", "Golem", "Virus" };
	string heronameP1;
	string heronameP2;
	for (int h = 0; h < 2; h++) {
		cout << "Daftar Hero :" << endl;
		for (int i = 0; i < herolist.size(); i++) {
			cout << i + 1 << ". " << herolist[i] << endl;
		}
		if (h == 0) {
			cout << "Pilihan --> ";
			cin >> heronameP1;
			if (heronameP1 == "1") {
				player1.setHeroname("Ragna");
			}
			else if (heronameP1 == "2") {
				player1.setHeroname("Shadow");
			}
			else if (heronameP1 == "3") {
				player1.setHeroname("Golem");
			}
			else if (heronameP1 == "4") {
				player1.setHeroname("Virus");
			}
			system("cls");
		}
		else if (h == 1) {
			cout << "Pilihan --> ";
			cin >> heronameP2;
			if (heronameP2 == "1") {
				player2.setHeroname(heronameP2);
			}
			else if (heronameP2 == "2") {
				player2.setHeroname("Shadow");
			}
			else if (heronameP2 == "3") {
				player2.setHeroname("Golem");
			}
			else if (heronameP2 == "4") {
				player2.setHeroname("Virus");
			}
			system("cls");
		}
	}
	// Setting Hero Player 1 dan Player 2 END Here


	// Setting Hero Attribute on Player START Here

	vector<int> heroHealthCap = { 1000, 800, 2500, 600 };
	vector<int> heroBasicDemage = { 20, 30, 10, 5 };
	vector<string> herotype = { "Fighter", "Assassin", "Tank", "Mage" };
	vector<vector<string>> skillName = { {"Ragna Wave", "Ragna Shock", "Ragna Ultimate"}, {"Toxic Shadow", "Shadow Move", "Shadow Ultimate"}, {"Golem Wall", "Golem Vengeance", "Golem Ultimate"}, {"Virus Illusion", "Virus Spell", "Virus Ultimate"} };
	vector<vector<int>> skillDemage = { {40, 60, 120}, {55, 70, 180}, {30, 45, 70}, {80, 155, 250} };
	vector<vector<int>> skillCooldown = { {3, 4, 5}, {2, 3, 4}, {4, 5, 6}, {2, 2, 3} };

	// Mencari index attribut setiap player START Here
	int indexOfP1;
	int indexOfP2;
	for (int i = 0; i < herolist.size(); i++) {
		if (herolist[i] == player1.getHeroname()) {
			indexOfP1 = i;
		}

		if (herolist[i] == player2.getHeroname()) {
			indexOfP2 = i;
		}
	}
	// Mencari index attribut setiap player END Here

	// Setting attribut player 1
	player1.setHealthCapacity(heroHealthCap[indexOfP1]);
	player1.setHealth(heroHealthCap[indexOfP1]);
	player1.setDefendCapacity(30);
	player1.setDefend(0);
	player1.setDemage(heroBasicDemage[indexOfP1]);
	player1.setHerotype(herotype[indexOfP1]);
	for (int i = 0; i < skillName[0].size(); i++) {
		player1.setSkill(skillName[indexOfP1][i]);
	}
	for (int i = 0; i < skillDemage[0].size(); i++) {
		player1.setSkillDemage(skillDemage[indexOfP1][i]);
	}
	for (int i = 0; i < skillCooldown[0].size(); i++) {
		player1.setSkillCooldown(skillCooldown[indexOfP1][i]);
	}

	// Setting attribut player 2
	player2.setHealthCapacity(heroHealthCap[indexOfP2]);
	player2.setHealth(heroHealthCap[indexOfP2]);
	player2.setDefendCapacity(30);
	player2.setDefend(0);
	player2.setDemage(heroBasicDemage[indexOfP2]);
	player2.setHerotype(herotype[indexOfP2]);
	for (int i = 0; i < skillName[0].size(); i++) {
		player2.setSkill(skillName[indexOfP2][i]);
	}
	for (int i = 0; i < skillDemage[0].size(); i++) {
		player2.setSkillDemage(skillDemage[indexOfP2][i]);
	}
	for (int i = 0; i < skillCooldown[0].size(); i++) {
		player2.setSkillCooldown(skillCooldown[indexOfP2][i]);
	}

	// Setting Hero Attribute on Player END Here


	// Permainan START Here
	bool keepPlaying = true;

	while (keepPlaying) {
		system("cls");

		// Show Intro Game
		cout << "WELCOME TO MAGIC ROYAL!!!" << endl;
		if (player1.getHealth() != player1.getHealthCapacity() || player2.getHealth() != player2.getHealthCapacity()) {
			cout << "==============================================" << endl;
			cout << "PEMENANG : ";
			if (player1.getHealth() > player2.getHealth()) {
				cout << player1.getUsername() << endl;
			}
			else if (player2.getHealth() > player1.getHealth()) {
				cout << player2.getUsername() << endl;
			}
			else {
				cout << "Belum ada pemenang" << endl;
			}
		}
		cout << "Player 1 (Health : " << player1.getHealth() << ") = " << player1.getUsername() << endl;
		cout << "Player 2 (Health : " << player2.getHealth() << ") = " << player2.getUsername() << endl;
		cout << "MENU GAME : " << endl;
		cout << "1. Start Game" << endl;
		cout << "0. EXIT" << endl;
		cout << "pilihan --> ";
		char choose;
		cin >> choose;
		if (choose == '1') {
			// Setting batas permainan sampai maksimal 100 turn
			bool poisonP1 = false;
			bool poisonP2 = false;
			int poisonP1turn = 0;
			int poisonP2turn = 0;

			// Skill Cooldown
			vector<int> skillCooldownP1 = { 0, 0, 0};
			vector<int> skillCooldownP2 = { 0, 0, 0};
			bool isTurnDone = true;
			for (int i = 0; i < 100; i++) {
				system("cls");
				// Cek apakah ada yang kalah H <= 0
				if (player1.getHealth() <= 0 || player2.getHealth() <= 0) {
					break;
				}
				string turn;
				if (i % 2 == 0) {
					turn = player1.getUsername();
				}
				else {
					turn = player2.getUsername();
				}

				if (turn == player1.getUsername()) {
					player1.showPlayerDetail();
				}
				else if (turn == player2.getUsername()) {
					player2.showPlayerDetail();
				}

				// Cek Efek Healer
				if (turn == player1.getUsername()) {
					for (int x = 0; x < player1.getBlessing().size(); x++) {
						if (player1.getBlessing()[x] == "Healer") {
							player1.healerEffect();
						}
					}
				}
				else {
					for (int x = 0; x < player2.getBlessing().size(); x++) {
						if (player2.getBlessing()[x] == "Healer") {
							player2.healerEffect();
						}
					}
				}

				// Cek Efek Poison

				if (turn == player1.getUsername()) {
					if (!poisonP1) {
						for (int x = 0; x < player1.getBlessing().size(); x++) {
							if (player1.getBlessing()[x] == "Poison") {
								poisonP1 = true;
								poisonP1turn = poisonP1turn + 3;
							}
						}
					}
					else {
						if (poisonP1turn != 0) {
							cout << "You Have poison for " << poisonP1turn << " turn" << endl;
							poisonP1turn = poisonP1turn - 1;
							player2.poisonEffect();
						}
						else {
							player1.removeBlessing("Poison");
							poisonP1 = false;
						}
					}
				}
				else {
					if (!poisonP2) {
						for (int x = 0; x < player2.getBlessing().size(); x++) {
							if (player2.getBlessing()[x] == "Poison") {
								poisonP2 = true;
								poisonP2turn = poisonP2turn + 3;
							}
						}
					}
					else {
						if (poisonP2turn != 0) {
							cout << "You Have poison for " << poisonP2turn << " turn" << endl;
							poisonP2turn = poisonP2turn - 1;
							player1.poisonEffect();
						}
						else {
							player2.removeBlessing("Poison");
							poisonP2 = false;
						}
					}
				}

				// Cek Efek Silent
				if (turn == player1.getUsername()) {
					for (int x = 0; x < player1.getBlessing().size(); x++) {
						if (player1.getBlessing()[x] == "Silent") {
							int chance = rand() % 5;
							if (chance == 0) {
								cout << "Berhasil mengirimkan efek silent ke " << player2.getUsername() << endl;
								system("pause");
								i = i + 1;
							}
						}
					}
				}
				else {
					for (int x = 0; x < player2.getBlessing().size(); x++) {
						if (player2.getBlessing()[x] == "Silent") {
							int chance = rand() % 5;
							if (chance == 0) {
								cout << "Berhasil mengirimkan efek silent ke " << player1.getUsername() << endl;
								system("pause");
								i = i + 1;
							}
						}
					}
				}

				// Cek Efek Dominance
				bool dominanceP1 = false;
				bool dominanceP2 = false;

				if (!dominanceP1) {
					for (int x = 0; x < player1.getBlessing().size(); x++) {
						if (player1.getBlessing()[x] == "Dominance") {
							dominanceP1 = true;
							player1.setDefendCapacity(60);
							player1.setDefend(15);
						}
					}
				}
				if (!dominanceP2) {
					for (int x = 0; x < player2.getBlessing().size(); x++) {
						if (player2.getBlessing()[x] == "Dominance") {
							dominanceP2 = true;
							player2.setDefendCapacity(60);
							player2.setDefend(15);
						}
					}
				}
				// Kurangi Cooldown skill tiap turn;
				if (turn == player1.getUsername()) {
					for (int i = 0; i < skillCooldownP2.size(); i++) {
						if (skillCooldownP2[i] != 0) {
							if (isTurnDone) {
								skillCooldownP2[i] = skillCooldownP2[i] - 1;
							}
						}
					}
				}
				else {
					for (int i = 0; i < skillCooldownP1.size(); i++) {
						if (skillCooldownP1[i] != 0) {
							if (isTurnDone) {
								skillCooldownP1[i] = skillCooldownP1[i] - 1;
							}
						}
					}
				}
				

				cout << "Choose action below : " << endl;
				cout << "1. Basic Attack" << endl;
				cout << "2. Get blessing" << endl;
				cout << "3. Skill" << endl;
				if (turn == player1.getUsername()) {
					for (int i = 0; i < player1.getSkill().size(); i++) {
						cout << "--> (" << i + 1 << ") " << player1.getSkillOf(i) << " (CD : " << skillCooldownP1[i] << ")" << endl;
					}
				}
				else if (turn == player2.getUsername()) {
					for (int i = 0; i < player2.getSkill().size(); i++) {
						cout << "--> (" << i + 1 << ") " << player2.getSkillOf(i) << " (CD : " << skillCooldownP2[i] << ")" << endl;
					}
				}
				cout << "0. Exit Battle" << endl;
				char action;
				cout << "SELECT Action --> ";
				cin >> action;
				if (action == '1') {
					if (turn == player1.getUsername()) {
						player2.attackedWithBasic(player1.getDemage());
						isTurnDone = true;
					}
					else {
						player1.attackedWithBasic(player2.getDemage());
						isTurnDone = true;
					}
					system("pause");
				}
				else if (action == '2') {
					if (turn == player1.getUsername()) {
						player1.findBlessing();
						isTurnDone = true;
					}
					else {
						player2.findBlessing();
						isTurnDone = true;
					}
					system("pause");
				}
				else if (action == '3') {
					int indexSkill;
					cout << "Skill number --> ";
					cin >> indexSkill;
					if (turn == player1.getUsername()) {
						if (skillCooldownP1[indexSkill - 1] == 0) {
							isTurnDone = true;
							cout << endl << player1.getUsername() << " Menggunakan skill " << player1.getSkillOf(indexSkill - 1) << endl;
							player2.attackedWithSkill(player1.getSkillDemageOf(indexSkill - 1));
							skillCooldownP1[indexSkill - 1] = skillCooldownP1[indexSkill - 1] + player1.getSkillCooldownOf(indexSkill - 1);
						}
						else {
							isTurnDone = false;
							cout << "Skill " << player1.getSkillOf(indexSkill - 1) << " Masih Cooldown" << endl;
							i = i - 1;
						}
					}
					else {
						if (skillCooldownP2[indexSkill - 1] == 0) {
							isTurnDone = true;
							cout << endl << player2.getUsername() << " Menggunakan skill " << player2.getSkillOf(indexSkill - 1) << endl;
							player1.attackedWithSkill(player2.getSkillDemageOf(indexSkill - 1));
							skillCooldownP2[indexSkill - 1] = skillCooldownP2[indexSkill - 1] + player2.getSkillCooldownOf(indexSkill - 1);
						}
						else {
							isTurnDone = false;
							cout << "Skill " << player2.getSkillOf(indexSkill - 1) << " Masih Cooldown" << endl;
							i = i - 1;
						}
					}
					system("pause");
				}
				else if (action == '0') {
					string confirm;
					cout << "Yakin ingin berhenti ? (Y/n) --> " << endl;
					cin >> confirm;
					if (confirm == "Y" || confirm == "y") {
						break;
					}
					else {
						i = i + 1;
					}
				}
			}
		}
		else if (choose == '0') {
			keepPlaying = false;
		}
	}
	// Permainan END Here

	return 0;
}