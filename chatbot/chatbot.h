// chatbot.h
//
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
//
// You can #include any standard C++ files, but do not use any other outside
// code (unless you write it).
//
//Author: Sahaj Karan
//Student number: 301386551
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

class Chatbot{
	public:	
		string name;
		string get_reply();
		string get_name();
		void tell(string input);
		Chatbot(char const* name1);
		
		int replyy=0;//reply counter
		int start=0;
		int repeat_1=0;
		int repeat_2=0;
		string user_name;
};

int randInt(int a){	//Helper function to get random numbers.
	int num=rand()%a;
	return num;	//returns a random number so that we have a random response.
}
int substring(string check, string input){ //Returns true if check string is in input string.
	// This hleper function will help us find certain key words to determine our responses.
	int len_check=check.length(); //Gets length of check string.
	int len_input=input.length(); //Gets length of input string.
	
	for(int i=0;i<=len_input - len_check;i++){
		
		int j;
		for( j=0;j<len_check;j++)
			if(input[i+j]!=check[j]) //If elements are differnt end nested loop and check next i itteration of the main loop.
				break;

		if(j==len_check)	//If the j goes upto the size of the substring it returns true meaning the string exists in the parent string.
			return 1;	
	}
	return -1;
}									

Chatbot :: Chatbot(char const* name1){
	name=name1;
}
	// This will have multiple user input and keywords will be used to determine a valid response
void Chatbot :: tell(string input){
	
	transform(input.begin(),input.end(),input.begin(), ::tolower); //Converts the entire string to lower case strings..
	string testing=input;
	
	//Using the substring function to find certain keywords to determine an appropriate response.
    if((substring("hello",input)==1) || (substring("hi",testing)==1) || (substring("hey",testing)==1) ){
		replyy=1;
	}
	else if((substring("i am good",input)==1)|| (substring("i am great",input)==1)|| (substring("good",input)==1)|| (substring("i am okay",input)==1) || (substring("i am good",input)==1)){
		replyy=2;		
	}
	else if((substring("not good",input)==1) || (substring("bad",input)==1)){
		replyy=3;
	}
	else if((substring("more soccer",input))==1 || (substring("soccer facts",input))==1 ){
		replyy=4;
	}
	else if((substring("yes",input))==1){
		replyy=13;
	}
	else if((substring("no",input))==1){
		replyy=5;
	}
	else if((substring("stop",input))==1 || (substring("shut up",input))==1 || (substring("exit",input))==1 || (substring("end",input))==1){
		replyy=6;
	}
	else if((substring("basketball facts",input))==1||(substring("more basketball",input))==1){
		replyy=7;
	}
	else if((substring("why",input))==1){
		replyy=8;
	}
	else if((substring("more",input))==1){
		replyy=9;
	}
	else if(((substring("players",input))==1)||(substring("player",input))==1){
		replyy=10;
	}
	else if((substring("soccer",input))==1){
		replyy=11;
	}
	else if((substring("basketball",input))==1){
		replyy=12;
	}
	else if((substring("bye",input))==1){
		replyy=14;
	}
	else if((substring("how are you",input))==1){
		replyy=15;
	}
	else if((substring("what can you do?",input))==1){
		replyy=16;
	}
	else if((substring("what is your name?",input))==1){
		replyy=17;
	}
	else if((substring("wow",input))==1){
		replyy=18;
	}
	else if( (substring("i am sad",input))==1 || (substring("sad",input))==1){
		replyy=19;
	}
	else if((substring("thank you",input))==1){
		replyy=20;
	}
	else if((substring("game",input))==1){
		replyy=21;
	}
	else if(replyy==0){
		replyy=0;
	}
	else{
		replyy=999;
	}
}
//In get_reply we will store our responses that we will give to the user depending on their input.
string Chatbot :: get_reply(){
	
	if(replyy==0){ //If the user enters anything except hello in the start it will promt the user to say hello so that sequence of the conversation can be controlled
		string hi[3]={"Maybe start off with a Hello ?",
					  "A hi would be nice ?",
					  "Maybe say hey ?"};
		return hi[randInt(3)];
	}

	if(replyy==1){
		string hello_reply[3]={"Hi.I am chatty i specialize in sports facts and I can also play a game with you just say game if you want to. Anyways How are you?",
							   "Hello.Chatty this side a fun fact about me is i know alot of sports related facts and I can play a game with you if you say game. Anyways How are you doing?",
							   "Hey.I am chatty someone that is great a rembering sports facts and have interesting questions for a would you rather game.Just say game if you want to play.Anyways How's it going?"};
		
		repeat_1++;
		if(repeat_1==3){	//This stores how many times the user repeats hello if its excessive the program will promt it out..
			return"Were two hello's not enough xd?";
		}
		else if(repeat_1>=4){
			return"Stop it now. Its getting boring tell me how you are feeling good or bad?";
		}
		else{

		return hello_reply[randInt(3)];	//We also keep mutiple reponses so the conversation is not dull everytime the user runs the program.
		}
	}
	
	else if(replyy==2){
		string gmood_reply[5]={"Thats good to hear. Would you like to play a game? Just say game to start?",
	    					   "Amazing. Want me to tell you fun facts about soccer?",
	        				   "Fantastic I feel the same. Would you like to know fun facts about soccer by any chance", 
	        				   "Aye good to know. Would you like to hear fun facts about soccer?",
	        				   "Do you want to play a game ? just say game if you would like to xd"};
		
		repeat_2++;
		if(repeat_2==2){
			return"good to hear that you are doing good. Would you like to hear about soccer facts?";
		}
		else if(repeat_2>4){
			return"Stop it now. I get it you are feeling good";
		}
		else{
		return gmood_reply[randInt(5)];
		}
	}
	
	else if(replyy==3){
		string bmood_reply[3]={"Um. Thats sad. Maybe fun facts about soccer would cheer you up?",
							   "I understand hope it gets better. Soccer always makes me feel better can I tell you interesting facts about soccer?",
		                       "It will get better.Maybe a game of would you rather will cheer you up.Just say game if you want to play."};
		
		return bmood_reply[randInt(3)];
	}	
	
	else if(replyy==4){
		string soccer_facts[10]={"Football was invented in China nearly 476 B.C. Say yes if you want more facts based on soccer",
		                        "Only Canadians and Americans call football as Soccer. Say yes if you want more facts based on soccer",
		                        "The first game of Basketball was played with a soccer ball. Say yes if you want more facts based on soccer",
		                        "The total length of the football field is 100 yards. Say yes if you want more facts based on soccer",
		                        "One of the fastest goal was in 2.8 seconds made by Ricardo Olivera in December 1998. Say yes if you want more facts based on soccer",
		                        "Until 1913, Goalies did not wear different colored shirts from their teammates. Say yes if you want more facts based on soccer",
		                        "A referee’s call during a football match in Peru caused a riot that killed over 300 people and injured over 500 people  in 1964. Say yes if you want more facts based on soccer",
		                        "Lightning killed an entire football team during a game in 1998. Say yes if you want more facts based on soccer",
		                        "Neil Armstrong wanted to take a football to the moon, but NASA refused it. Say yes if you want more facts based on soccer",
		                        "Greenland cannot join the FIFA because not enough grass grows for a football field. Say yes if you want more facts based on soccer"};
		 int any = 0 ; //The following code asks if the user would like another fact and we determine this with a counter.
        while (any == 0) {
            cout << "Chatty" << "> " << soccer_facts[randInt(10)] << "\n\n";//Asking the user to enter a string
		    cout << "You> ";
		    string new_input;
		    getline(cin, new_input);  // reads entire line of input
            transform(new_input.begin(),new_input.end(),new_input.begin(), ::tolower);	//Converting the string to all lower case.
            if(new_input=="wow"){
            	cout<<"I had the same reaction xd"<<endl;
            }
            if (new_input != "yes"){	//If the string input is equal to yes it will print another fact
                any ++;
            }	//Otherwise our code will stop and give suggestions about what else we can do.
        }  
		return "Ok i will stop for now.Just say basketball or soccer facts if you would like to know more?";
	}
	
	else if(replyy==5){
		string no_reply[2]={"Oh thats unfortunate.Just say soccer/basket facts in case you change your mind or say players if you would like info on some players as well",
		                    "Um ok. Well I have information about certain players if you would like to know about them just say player or I could tell you facts about socccer or basketball"};
		return no_reply[randInt(2)];
	}
	
	else if(replyy==6){
		return"Ok i will stop for now.Just say basketball facts or soccer facts if you would like to know more?";
	}
	
	else if(replyy==7){
		string basketball_facts[9]={"Basketball was played by using a soccer ball until 1929. Just say yes for more Basketball facts",
		                            "Michael Jordan (goat) has scored more playoff points than anyone else. Just say yes for more Basketball facts",
		                            "Slam dunks were illegal for almost nine years. Just say yes for more Basketball facts",
		                            "The steel rim of the basket has a diameter of 18 inches and is 10 feet high. Just say yes for more Basketball facts",
		                            "Kobe Bryant was only 17 when he entered the NBA. Just say yes for more Basketball facts",
		                            "The court surface is 94 by 50 feet. Just say yes for more Basketball facts",
		                            "Basketball was first played on December 21, 1891. Just say yes for more Basketball facts",
		                            "The first backboards were made of wire. Just say yes for more Basketball facts",
		                            "Karl Malone holds the record for free throws. Just say yes for more Basketball facts"};
		
        int any = 0 ;
        while (any == 0) {
            cout << "Chatty" << "> " << basketball_facts[randInt(9)] << "\n\n";
		    cout << "You> ";
		    string new_input;	//getting new input from user 
		    getline(cin, new_input);  // reads entire line of input
            transform(new_input.begin(),new_input.end(),new_input.begin(), ::tolower);
            if(new_input=="wow"){
            	cout<<"I had the same reaction xd"<<endl;
            }
            if (new_input != "yes"){
                any ++;
            }
        }     
        return"Ok i will stop for now. Just say basketball or soccer facts if you would like to know more?";
        
	}
	
	else if(replyy==8){
		return "Why is always a good question.If you mean why I know these facts even I dont know I just do";
	}
	
	else if(replyy==9){
		return "More soccer facts or basketball or would you like to know a few things about famous players?";
	}
	
	else if(replyy==10){
		string plays[2]={"Would you like to know about basketball players or soccer players",
						 "I know about soccer players and basketball players as well. Which one would you like to know about ?"};
		return plays[randInt(2)];
	}
	
	else if(replyy==11){
		string soccer_players[5]= {"The 1st highest paid player (€131 million) is Lionel Messi ,born 24 June 1987, is an Argentine professional footballer who plays as a forward and captains"
								    "both Spanish club Barcelona and the Argentina national team." 
									"Often considered the best player in the world and widely regarded as one of the greatest players of all time, Messi has won a record "
									"six Ballon dOr awards. Say yes if you want to know about more about other soccer players",
								  
								   "The 2nd highest paid player (€118 million) is Cristiano Ronaldo born 5 February 1985, is a Portuguese professional footballer who plays as a forward for Serie A"
								   "club Juventus and captains the Portugal national team. Often considered the best player in the world and widely regarded as one of the greatest players of all time,"
								   "Ronaldo has won five Ballon dOr and four European Golden Shoes. Say yes if you want to know more about other soccer players",

								   "The 3rd highest paid player (€98 million) is Neymar, born 5 February 1992, is a Brazilian professional footballer who"
								   "plays as a forward for Ligue 1 club Paris Saint-Germain and the Brazil national team. Say yes if you want to know more about other soccer players",

								   "The 4th highest paid player (€40 million)  is Gareth Bale, born 16 July 1989, is a Welsh professional footballer who plays as a winger"
								   "for Spanish La Liga club Real Madrid and the Wales national team."
								   "Renowned for his ball striking from distance, swerving free kicks,"
								   "and his ability to get past defenders with pace, Bale has received plaudits from his peers, who have described him as a footballer with tremendous speed, great crossing ability,"
								   "a great left foot and exceptional physical qualities. Say yes if you would like to know more aboud different soccer players",

								   "The 5th highest paid player (€37 million) is Antoine Griezmann,born 21 March 1991,is a French professional footballer"
								   "who plays as a forward for Spanish club Barcelona and the French national team. Say yes if you would like more facts about soccer players"};
								   
       
        int any = 0 ;
        while (any == 0) {
            cout << "Chatty" << "> " <<soccer_players[randInt(5)] << "\n\n";
		    cout << "You> ";
		    string new_input;
		    getline(cin, new_input);  // reads entire line of input
            transform(new_input.begin(),new_input.end(),new_input.begin(), ::tolower);
            if(new_input=="wow"){
            	cout<<"I had the same reaction xd"<<endl;
            }
            if (new_input != "yes"){
                any ++;
            }
        } 
        return "Oh i will stop for now.Just say players if you would like to know about highest paid players in soccer or basketball or say game if you want to play Would you Rather.";
	}

	else if(replyy==12){
		string basketball_players[5]={"The 1st highest paid basketball player ($134 million) is LeBron James,born December 30, 1984, is an American professional basketball player for the Los Angeles Lakers of the National Basketball Association (NBA)"						   
									  ".He is widely considered to be one of the greatest basketball players in NBA history.James's teams have played in eight consecutive NBA Finals (2011–2018 seasons).Say yes if you would like to know about more basketball players",
								  
								  	 "The 2nd highest paid basketball player ($124 million) is Steph Curry,born March 14, 1988[1]) is an American professional basketball player for the Golden State Warriors of the National Basketball Association (NBA)." 
								   	 "A six-time NBA All-Star, Curry has been named the NBA Most Valuable Player (MVP) twice and won three NBA championships with the Warriors.Say yes if you would like to know about more basketball players"
								     "Many players and analysts have called him the greatest shooter in NBA history.Say yes if you would like to know about more basketball players",

								     "The 3rd highest paid basketball player ($104 million) is Kevind Durantborn September 29, 1988) is an American professional basketball player for the Brooklyn Nets of the National Basketball Association (NBA)."
								     "He played one season of college basketball for the University of Texas,"
								     "and was selected as the second overall pick by the Seattle SuperSonics in the 2007 NBA draft.Say yes if you would like to know about more basketball players ",
 
								     "The 4th highest paid basketball player ($82.8 million) is Russell Westbrook,born November 12, 1988) is an American professional basketball player for the Houston Rockets of the National Basketball Association (NBA)."
								     "He is a nine-time NBA All-Star and earned the NBA Most Valuable Player Award for the 2016–17 season. He is also an eight-time All-NBA Team member,"
								     "led the league in scoring in 2014–15 and 2016–17, and won back-to-back NBA All-Star Game.Say yes if you would like to know about more basketball players",

								     "The 5th highest paid basketball player ($80.9 million) is James Harden,born August 26, 1989) is an American professional basketball player for the Houston Rockets of the National Basketball Association (NBA)."
								     "He played college basketball for Arizona State, where he was named a consensus All-American and Pac-10 Player of the Year in 2009.Say yes if you would like to know about more basketball players" };

       
        int any = 0 ;
        while (any == 0) {
            cout << "Chatty" << "> " << basketball_players[randInt(5)] << "\n\n";
		    cout << "You> ";
		    string new_input;
		    getline(cin, new_input);  // reads entire line of input
            transform(new_input.begin(),new_input.end(),new_input.begin(), ::tolower);
            if(new_input=="wow"){
            	cout<<"I had the same reaction xd"<<endl;
            }
            if (new_input != "yes"){
                any ++;
            }
        } 
        return "Oh i will stop for now.Just say players if you would like to know about highest paid players in soccer or basketball.";

	}

	else if(replyy==13){
		return "Yes?. Yes for basketball facts , soccer facts or facts about players we can even play a game if you enter game.";
	}

    else if(replyy==14){
    	cout<<"Going already :( Take care. See you again soon.";
		exit(0);
	}

	else if(replyy==15){
		string thanks_reply[3]={"I am doing just alright. Thanks for asking maybe also ask me I know any basketball facts?",
							   "I am happy today. Would you like to know a fact about soccer?",	
							   "Aww. I am good thank you. Would you like to play a game of Would you rather then. Just say game to start?"};
																									
		return thanks_reply[randInt(3)];
	}

	else if(replyy==16){
		return "Not much but if you say soccer facts i will give you soccer facts, if you say basketball facts I will give you basketball facts, if you say players I will give you player facts.If you say game then we can play a game of would you rather as well";
	}
	else if(replyy==17){
		return "My name is Chatty";
	}
	else if(replyy==18){
		string wow[2]={"I know right I had the same reaction when I learnt this",
					   "I had the same reaction haha."};
		return wow[randInt(2)];
	}
	else if(replyy==19){
		string quote[5]={"Don’t give up when dark times come. The more storms you face in life, the stronger you’ll be. Hold on. Your greater is coming.",
						 "Let us be of good cheer, however, remembering that the misfortunes hardest to bear are those which never come.",
						 "Cheer up, my dear. After every storm comes the sun. Happiness is waiting for you ahead.",
						 "What doesn’t kill you makes you stronger.",
						 "Sometimes your heart needs more time to accept what your mind already knows."};
		return quote[randInt(5)];
	}
	else if(replyy==20){
		return "You are welcome.";
	}
	else if(replyy==21){
		// This portion is for a game if the user decides to play.
		string game_questions[5]{"Would you rather lose the ability to read or lose the ability to speak? Just say left or right as your ans.",
								 "Would you rather be covered in fur or covered in scales? Just say left or right as your ans.",
								 "Would you rather be in jail for a year or lose a year off your life? Just say left or right as your ans.",
								 "Would you rather know the history of every object you touched or be able to talk to animals? Just say left or right as your ans.",
								 "Would you rather be the first person to explore a planet or be the inventor of a drug that cures a deadly disease? Just say left or right as your ans."};
		int any = 0 ;
		cout<<"The name of the game is Would You Rather"<<endl;
		cout<<"To stop the game just enter stop"<<endl;
       	int i=0;
        while (any == 0) {

        	
            cout << "Chatty" << "> " << game_questions[i] << "\n\n"; 
		    cout << "You> ";
		    string new_input;	//Getting a new input form the user to store his ans
		    getline(cin, new_input);  // reads entire line of input
            transform(new_input.begin(),new_input.end(),new_input.begin(), ::tolower); //converting it to lower case
            if(new_input=="stop"){
	           	any=1; //If the user enters stop end the loop
            	break;
            }
            if(i==0){	//Pre defined ans for the questions to make it feel like a conversation.
            	if(new_input=="left"){
            		cout<<"Yea I feel the same ability to speak for the win."<<endl;
            	}
            	else{
            		cout<<"You must really like reading then"<<endl;
            	}
            }
            if(i==1){
            	if(new_input=="left"){
            		cout<<"Yea I feel the same like having fur would be comfortable haha."<<endl;
            	}
            	else{
            		cout<<"What will you do with snake skin lol."<<endl;
            	}
            }
             if(i==2){
            	if(new_input=="left"){
            		cout<<"I prefer the jail option as well. You know go get ripped better then losing a year."<<endl;
            	}
            	else{
            		cout<<"Interesting choice. But I would rather choose jail."<<endl;
            	}
            }
             if(i==3){
            	if(new_input=="left"){
            		cout<<"Interesting choice. I prefer the ability to talk to animals imagine the possibility with your pet dog you will never be lonely xd."<<endl;
            	}
            	else{
            		cout<<"Good choice. I would also like to talk to animals. I often wonder what my dogs says to other dogs lol."<<endl;
            	}
            }
             if(i==4){
            	if(new_input=="left"){
            		cout<<"That would be so sick. Don’t foget me when you become famous for that."<<endl;
            	}
            	else{
            		cout<<"Inventing a new drug seems so ideal right now. Hope things get better soon."<<endl;
            	}
            }
            i++;
            if(i>4){
            	any=1;//ending the loop
            }
            
        } 
        return"That was fun";

	}
    else if(replyy==999){//This section is when the chatbot does not recognize the input user provides and give him other options.
    	string dont_understand[5]={"I dont understand. Maybe say Basketball facts?", 
    							   "Maybe ask me something else? Maybe say soccer for facts about Soccer players?",
    							   "I am not sure what you mean. Maybe ask me about Basketbal facts?",
    							   "Im confused uf. I know alot of Basketball facts just say it and i will tell you some",
    							   "I dont quite understand. Maybe try telling me how you are feeling good or bad ?"};
		return dont_understand[randInt(5)];
	}
	
return "Say Hello";

}

string Chatbot :: get_name(){
	return name;
}

