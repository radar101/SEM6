#include<bits/stdc++.h>
using namespace std;

/*
    Components of an Expert System:
        1. Knowledge Base : Contains facts and rules
        2. Inference Engine : makes decisions
        3. User Interface : interact with the user
*/

// Help Desk Management
// Responses for various inquiries.
unordered_map<string, string> responses = {
    {"greeting", "Hello! Welcome to our mobile repair shop. How can I assist you today?"},
    {"farewell", "Thank you for choosing our mobile repair services. Have a great day!"},
    {"help", "Sure, I'm here to help. What issues are you facing with your mobile?"},
    {"screen_cracked", "A cracked screen is a common issue. We can replace the screen for you."},
    {"battery_problem", "If you're experiencing battery issues, we can replace your mobile's battery."},
    {"software_issue", "Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that."},
    {"water_damage", "Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair."},
    {"charging_issue", "If your mobile is not charging properly, it could be due to a faulty charging port or cable. We can diagnose and fix the issue at our shop."},
    {"network_problem", "If you're experiencing network or signal issues, it could be related to your mobile's antenna or network settings."},
    {"speaker_issue", "If you're having trouble with your mobile's speaker or microphone, it might be a hardware or software issue."},
    {"button_not_working", "If the buttons on your mobile are not working, it could be due to physical damage or software issues."},
    {"slow_performance", "If your mobile is running slow, it might be overloaded with apps or have software issues."},
    {"default", "I apologize, but I couldn't understand your request. Please contact our customer support for assistance."}
};

// Some follow-up questions.
unordered_map<string, vector<string>> questions = {
    {"screen_cracked", {"Has the screen been cracked recently?", "Did the screen crack after dropping your phone?", "Is the touch functionality affected due to the crack?"}},
    {"battery_problem", {"Have you kept your mobile on power saver mode?", "Also remove all the background apps from the device", "How frequently do you charge your device?"}},
    {"software_issue", {"Have you tried restarting your device?", "When did you first notice the issue?", "Is the software up to date?"}},
    {"water_damage", {"Was your device exposed to water recently?", "In what circumstances did the exposure to water occur?", "Is the device completely non-functional now?"}},
    {"charging_issue", {"Have you tried using a different charging cable?", "Does the charging port look damaged?", "Have you tried charging the device from a different power source?"}},
    {"network_problem", {"Have you tried restarting your device to reset the network settings?", "Are other devices connected to the same network experiencing issues?", "Is the issue consistent across different network connections?"}},
    {"speaker_issue", {"Have you noticed any physical damage to the speaker or microphone?", "Does the issue occur during calls, media playback, or both?", "Have you tried using headphones to check the audio?"}},
    {"button_not_working", {"Have you installed any new apps recently?", "Did the buttons stop working after a recent software update?", "Are all the buttons affected or just specific ones?"}},
    {"slow_performance", {"Have you checked your device's storage capacity?", "When did you first notice the performance degradation?", "Does the device become warm during usage?"}},
    {"default", {""}}
};


// Rule class to hold pattern and response key
class Rule {
public:
    Rule(string pattern, string response_key) : pattern(pattern), response_key(response_key) {}
    string pattern;
    string response_key;
};

class ChatBot {
public:
    ChatBot(vector<Rule> rules) : m_rules(rules) {}
    pair<string, vector<string>> respond_to_inquiry(string inquiry) {
        // Convert inquiry to lowercase for case-insensitive matching
        transform(inquiry.begin(), inquiry.end(), inquiry.begin(), ::tolower);
        for (const auto& rule : m_rules) {
            regex pattern(rule.pattern);
            if (regex_search(inquiry, pattern)) {
                return {responses[rule.response_key], questions[rule.response_key]};
            }
        }
        return {responses["default"], questions["default"]};
    }
private:
    vector<Rule> m_rules;
};

int main() {
    cout << "Welcome to the Mobile Repair Help Desk!" << endl;
    cout << "Type 'exit' to end the conversation." << endl;

    // Define rules
    vector<Rule> rules = {
        Rule("\\b(?:hello|hi)\\b", "greeting"),
        Rule("\\b(?:goodbye|bye)\\b", "farewell"),
        Rule("\\b(?:help|support)\\b", "help"),
        Rule("\\b(?:screen|cracked)\\b", "screen_cracked"),
        Rule("\\b(?:battery|charge)\\b", "battery_problem"),
        Rule("\\b(?:software|update|reset)\\b", "software_issue"),
        Rule("\\b(?:water|damage)\\b", "water_damage"),
        Rule("\\b(?:charging|charge|power)\\b", "charging_issue"),
        Rule("\\b(?:network|signal)\\b", "network_problem"),
        Rule("\\b(?:speaker|microphone)\\b", "speaker_issue"),
        Rule("\\b(?:button|buttons)\\b", "button_not_working"),
        Rule("\\b(?:slow|performance|lag)\\b", "slow_performance")
    };

    ChatBot chatbot(rules);

    while (true) {
        string user_input;
        cout << "Customer: ";
        getline(cin, user_input);
        if (user_input == "exit") {
            break;
        }

        // Handle empty input
        if (user_input.empty()) {
            cout << "Please provide a valid input." << endl;
            continue;
        }

        auto response = chatbot.respond_to_inquiry(user_input);
        cout << "Expert: " << response.first << endl;

        // Ask follow-up questions if available
        if(response.second.size() > 0) {
            vector<string> que = response.second;
            int n = response.second.size();
            for (int i=0;i<n;i++) {
                cout << "Expert: " << que[i] << endl;
                string customer_response;
                cout << "Customer (Yes/No): ";
                getline(cin, customer_response);
                if (customer_response == "No") {
                    if(i == n-1) {
                        cout<<"Expert: I suggest please bring your device at our shop. We can diagnose and fix the issue.";
                        return 0;
                    }
                    continue;  // Proceed to next follow-up question
                } else if (customer_response == "Yes") {
                    string resp;
                    cout << "Expert: Did this solved your problem? (Yes/No): ";
                    
                    getline(cin, resp);
                    if (resp == "Yes") {
                        cout << "Expert: Thank you for using the Mobile Repair Help Desk. Goodbye!" << endl;
                        return 0;
                    } else {
                        if(i == n-1) {
                            cout<<"Expert: I suggest please bring your device at our shop. We can diagnose and fix the issue.";
                            return 0;
                        }
                        continue; 
                    }
                }
            }
        }
        
    }

    cout << "Thank you for using the Mobile Repair Help Desk. Goodbye!" << endl;
    return 0;
}