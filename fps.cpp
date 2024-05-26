#include <bits/stdc++.h>
#include <iostream>
#include<stack>
using namespace std;

struct Node {
    char player_name[100];
    int jersey_number;
    int goal;
    int got_red_card;
    int got_yellow_card;
    float pass_accuracy;
    char key_pass[100];
    Node* next;
};

stack<Node*> team_1;
stack<Node*> team_2;
stack<Node*> team_3;
stack<Node*> team_4;
stack<Node*> team_5;

/// Info Add Function.
void player_info_add() {
    int team;

    cout << "Team Number: ";
    cin >> team;
    cout << endl;

    Node* new_node = new Node();
    cout << "Enter Player Name: ";
    scanf("%*c%[^\n]", new_node->player_name);
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> new_node->jersey_number;
    cout << endl;

    cout << "Enter Goal Figure: ";
    cin >> new_node->goal;
    cout << endl;

    cout << "Enter Red Card Figure: ";
    cin >> new_node->got_red_card;
    cout << endl;

    cout << "Enter Yellow Card Figure: ";
    cin >> new_node->got_yellow_card;
    cout << endl;

    cout << "Enter The Percentage of Pass Accuracy: ";
    cin >> new_node->pass_accuracy;
    cout << endl;

    cout << "Key Pass, Yes or Not: ";
    scanf("%*c%[^\n]", new_node->key_pass);
    cout << endl;

    new_node->next = nullptr;

    switch (team) {
        case 1:
            team_1.push(new_node);
            break;
        case 2:
            team_2.push(new_node);
            break;
        case 3:
            team_3.push(new_node);
            break;
        case 4:
            team_4.push(new_node);
            break;
        case 5:
            team_5.push(new_node);
            break;
        default:
            cout << "This memory only takes 5 team data.";
    }
}

/// Display Function For Specific Match.
void display_team() {
    int team;
    cout << "Which teams info you need to see: ";
    cin >> team;
    cout << endl;

    stack<Node*> temp_stack;
    switch (team) {
        case 1:
            temp_stack = team_1;
            break;
        case 2:
            temp_stack = team_2;
            break;
        case 3:
            temp_stack = team_3;
            break;
        case 4:
            temp_stack = team_4;
            break;
        case 5:
            temp_stack = team_5;
            break;
        default:
            cout << "Sorry, there is nothing to print.\n";
            return;
    }

    if (temp_stack.empty()) {
        cout << "There is no info in the Match-" << team << " list.\n";
        return;
    }

    cout << "======================== Player info for team-" << team << " list ======================== " << endl;
    cout << endl;

    while (!temp_stack.empty()) {
        Node* temp = temp_stack.top();
        temp_stack.pop();

        cout << "Player Name: " << temp->player_name << endl;
        cout << "Jersey Number: " << temp->jersey_number << endl;
        cout << "Goal Figure: " << temp->goal << endl;
        cout << "Red Card Figure: " << temp->got_red_card << endl;
        cout << "Yellow Card Figure: " << temp->got_yellow_card << endl;
        cout << "Pass accuracy: " << temp->pass_accuracy << endl;
        cout << "Key pass: " << temp->key_pass << endl;
        cout << "\n";
    }

    cout << "\n";
}

/// Search Function Using Player Name and Player Jersey Number.
void search_player() {
    char name[100];
    int number;

    cout << "Enter Name: ";
    scanf("%*c%[^\n]", name);
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    stack<Node*> temp_stack[5] = {team_1, team_2, team_3, team_4, team_5};
    bool found = false;

    for (int i = 0; i < 5; i++) {
        while (!temp_stack[i].empty()) {
            Node* temp = temp_stack[i].top();
            temp_stack[i].pop();

            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number) {
                cout << endl;
                cout << ">>>>>>>>>>>>>> Team-" << i + 1 << " <<<<<<<<<<<<<<<" << endl;
                cout << endl;
                cout << "Player Name: " << temp->player_name << endl;
                cout << "Jersey Number: " << temp->jersey_number << endl;
                cout << "Goal Figure: " << temp->goal << endl;
                cout << "Red Card Figure: " << temp->got_red_card << endl;
                cout << "Yellow Card Figure: " << temp->got_yellow_card << endl;
                cout << "Pass accuracy: " << temp->pass_accuracy << "%" << endl;
                cout << "Key pass: " << temp->key_pass << endl;
                cout << endl;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "No Info available about the player.\n";
    }
}

/// This is for Updating Player Info.
void edit() {
    char name[100];
    int number, team;

    cout << "Enter Player Name: ";
    scanf("%*c%[^\n]", name);
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    cout << "Enter Team Number: ";
    cin >> team;
    cout << endl;

    stack<Node*> temp_stack;
    switch (team) {
        case 1:
            temp_stack = team_1;
            break;
        case 2:
            temp_stack = team_2;
            break;
        case 3:
            temp_stack = team_3;
            break;
        case 4:
            temp_stack = team_4;
            break;
        case 5:
            temp_stack = team_5;
            break;
        default:
            cout << "There is nothing to Edit.\n";
            return;
    }

    if (temp_stack.empty()) {
        cout << "There is nothing to Edit.\n";
        return;
    }

    bool found = false;
    stack<Node*> temp_buffer;

    while (!temp_stack.empty()) {
        Node* temp = temp_stack.top();
        temp_stack.pop();

        if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number) {
            found = true;

            cout << "Enter Update Player Name: ";
            scanf("%*c%[^\n]", temp->player_name);
            cout << endl;

            cout << "Enter Update Jersey Number: ";
            cin >> temp->jersey_number;
            cout << endl;

            cout << "Enter Update Goal Figure: ";
            cin >> temp->goal;
            cout << endl;

            cout << "Enter Update Red Card Figure: ";
            cin >> temp->got_red_card;
            cout << endl;

            cout << "Enter Update Yellow Card Figure: ";
            cin >> temp->got_yellow_card;
            cout << endl;

            cout << "Enter The Update Percentage of Pass Accuracy: ";
            cin >> temp->pass_accuracy;
            cout << endl;

            cout << "Key Pass: ";
            scanf("%*c%[^\n]", temp->key_pass);
            cout << endl;
        }
        temp_buffer.push(temp);
    }

    // Restore stack
    while (!temp_buffer.empty()) {
        temp_stack.push(temp_buffer.top());
        temp_buffer.pop();
    }

    switch (team) {
        case 1:
            team_1 = temp_stack;
            break;
        case 2:
            team_2 = temp_stack;
            break;
        case 3:
            team_3 = temp_stack;
            break;
        case 4:
            team_4 = temp_stack;
            break;
        case 5:
            team_5 = temp_stack;
            break;
    }

    if (!found) {
        cout << "Player not found.\n";
    }
}

/// Delete Function is for removing a player info.
void delete_player() {
    char name[100];
    int team_number, jersey_number;

    cout << "Enter Team Number: ";
    cin >> team_number;
    cout << endl;

    cout << "Enter Player Name: ";
    scanf("%*c%[^\n]", name);
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> jersey_number;
    cout << endl;

    stack<Node*> temp_stack;
    switch (team_number) {
        case 1:
            temp_stack = team_1;
            break;
        case 2:
            temp_stack = team_2;
            break;
        case 3:
            temp_stack = team_3;
            break;
        case 4:
            temp_stack = team_4;
            break;
        case 5:
            temp_stack = team_5;
            break;
        default:
            cout << "Invalid team number.\n";
            return;
    }

    if (temp_stack.empty()) {
        cout << "No players in teams " << team_number << endl;
        return;
    }

    stack<Node*> temp_buffer;
    bool found = false;

    while (!temp_stack.empty()) {
        Node* temp = temp_stack.top();
        temp_stack.pop();

        if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == jersey_number) {
            delete temp;
            found = true;
        } else {
            temp_buffer.push(temp);
        }
    }

    // Restore stack
    while (!temp_buffer.empty()) {
        temp_stack.push(temp_buffer.top());
        temp_buffer.pop();
    }

    switch (team_number) {
        case 1:
            team_1 = temp_stack;
            break;
        case 2:
            team_2 = temp_stack;
            break;
        case 3:
            team_3 = temp_stack;
            break;
        case 4:
            team_4 = temp_stack;
            break;
        case 5:
            team_5 = temp_stack;
            break;
    }

    if (found) {
        cout << "Player removed successfully.\n";
    } else {
        cout << "Player not found.\n";
    }
}

void undo_last_addition() {
    int team;
    cout << "Team Number to undo last addition: ";
    cin >> team;
    cout << endl;

    Node* removed_player = nullptr;
    switch (team) {
        case 1:
            if (!team_1.empty()) {
                removed_player = team_1.top();
                team_1.pop();
            }
            break;
        case 2:
            if (!team_2.empty()) {
                removed_player = team_2.top();
                team_2.pop();
            }
            break;
        case 3:
            if (!team_3.empty()) {
                removed_player = team_3.top();
                team_3.pop();
            }
            break;
        case 4:
            if (!team_4.empty()) {
                removed_player = team_4.top();
                team_4.pop();
            }
            break;
        case 5:
            if (!team_5.empty()) {
                removed_player = team_5.top();
                team_5.pop();
            }
            break;
        default:
            cout << "Invalid team number.\n";
            return;
    }

    if (removed_player != nullptr) {
        cout << "Removed player: " << removed_player->player_name << " (Jersey #" << removed_player->jersey_number << ")\n";
        delete removed_player;
    } else {
        cout << "No player to remove from Team-" << team << ".\n";
    }
}

void show() {
    stack<Node*> teams[5] = {team_1, team_2, team_3, team_4, team_5};

    for (int i = 0; i < 5; i++) {
        if (teams[i].empty()) {
            cout << "There is No Info in the Team-" << (i + 1) << " list." << endl;
            cout << endl;
        } else {
            cout << "======================== Player Info list for Team-" << (i + 1) << " ======================== " << endl;
            cout << endl;

            stack<Node*> temp_stack = teams[i];
            while (!temp_stack.empty()) {
                Node* temp = temp_stack.top();
                temp_stack.pop();

                cout << "Player Name: " << temp->player_name << endl;
                cout << "Jersey Number: " << temp->jersey_number << endl;
                cout << "Goal Figure: " << temp->goal << endl;
                cout << "Red Card Figure: " << temp->got_red_card << endl;
                cout << "Yellow Card Figure: " << temp->got_yellow_card << endl;
                cout << "Pass accuracy: " << temp->pass_accuracy << "%" << endl;
                cout << "Key pass: " << temp->key_pass << endl;
                cout << "\n";
            }

            cout << "\n";
        }
    }
}

int main() {
    cout << " ################    #########         ########             ########      ################          " << endl;
    cout << " ################    ##########        ##########         ##########      ################          " << endl;
    cout << " ###                 ###########       ###########       ###########      ####                      " << endl;
    cout << " ###                 ###########       ####    ####     ####    ####      ####                      " << endl;
    cout << " ########            #########         ####     ####   ####     ####      ################          " << endl;
    cout << " ########            #######           ####      #########      ####      ################          " << endl;
    cout << " ###                 ###               ####       #######       ####                  ####          " << endl;
    cout << " ###                 ###               ####        #####        ####                  ####          " << endl;
    cout << " ###                 ###               ####         ###         ####      ################          " << endl;
    cout << " ###                 ###               ####         ###         ####      ################          " << endl;
    cout << "####################################################################################################" << endl;
    cout << "####################################################################################################" << endl;
    cout << endl;
    cout << "******************* Welcome To The FootBall Player Management System ******************\n";
    cout << endl;

    while (true) {
        int choice;
        cout << "1. Add Player.\n";
        cout << "2. Edit PLayer.\n";
        cout << "3. Show PLayers.\n";
        cout << "4. Display Specific Team Info.\n";
        cout << "5. Search Player.\n";
        cout << "6. Delete Player.\n";
        cout << "7. Undo Last Addition.\n";
        cout << "8. Exit.\n";
        cout << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                player_info_add();
                break;
            case 2:
                edit();
                break;
            case 3:
                show();
                break;
            case 4:
                display_team();
                break;
            case 5:
                search_player();
                break;
            case 6:
                delete_player();
                break;
            case 7:
                undo_last_addition();
                break;
            case 8:                
                cout << " #######      ####      ####    #######       ####       ####      ##    " << endl;
                cout << " ########      ####    ####     ########       ####     ####       ##    " << endl;
                cout << " #########      ####  ####      #########       ####   ####        ##    " << endl;
                cout << " ########        #######        ########          #######          ##    " << endl;
                cout << " #####            ####          #####              #####           ##    " << endl;
                cout << " #######           ##           #######             ##             ##    " << endl;
                cout << " #########         ##           #########           ##                   " << endl;
                cout << " #########         ##           #########           ##             ##    " << endl;
                cout << " #######           ##           #######             ##             ##    " << endl;
                cout << " ########################################################################" << endl;
                cout << " ########################################################################" << endl;
                cout << endl;
                printf( " *************************** Exited FPMS ********************************");
                
                exit(0);
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
