#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
using namespace sf;


//variables.
Sound  titlescreen_music, menu_music, coin_sound, Levels_Music1, bossfight_music, ending_music;
SoundBuffer  titlescreen_music1, menu_music1, coin_sound1, Levels_Music, bossfight1_music, ending_music1;
Texture titlescreen, menu, ending, background_level_1, ring, sonic, enemy, boss, controls, level2Boss, springs;
Sprite titlescreen1[4], menu1, controls1[5], ending1[9], sonic1, background_level1[6], ring1[150], enemy1[10], boss1, bossCar1, bossE, bossM, springs1[7];
Font font;
Event event2, event3, event4;
Text menu2[8], LvlSel[5], currname, nom, scr, nam, scoretrack, ringstrack, scoretext, ringstext, highscore[3], countingscores;
const float  ground = 405;
float time1 = 0, ypos = ground, yvel = 0, bossspeed = 0, enemySpeed = 0;
int  currlevel = 0, Levels = 1, ring_rect = 0, ring_starting_position = 500, scoredrings = 0, xpos = 1400, collided = 10, spri = -1,
score = 0, highestscore = -10, LowestScore = 100000000, LowestIndex = 0, numofplayers, scores_count = 0, notmoving = 0, mover = 0, moveu = 0, moved = 0, movel = 0,
timedanimation1 = 0, timedanimation2 = 0, timedanimation3 = 0, timedanimation4 = 0,
bosscount = 0, bossCarcount = 0, bossEcount = 0, y = 0, bossMcount = 0, bosshit = 0, bosslives = 30, counter = 0,
TitleSpriteArr[20] = { 80, 150, 252, 169, 455, 170, 672, 179, 904, 162, 1082, 174, 1294, 184, 1521, 183 },
sspritearr[50] = { 178,68,248, 67,317, 66,385 ,67,454, 67,523 ,67,594,
                   73,670 ,67,741 ,69,815 ,78, 899 ,77,980 ,79,1062 ,91,
                   1156 ,91,1251 ,88,1345 ,86,1439 ,86,1531 ,63,1602 ,63 },
    dashspritearr[20] = { 543, 66, 612, 69, 699, 70, 775, 68, 849, 67, 920, 67, 991, 68, 1062, 68 },
    uspritearr[20] = { 1156, 67, 1234, 71, 1319, 68, 1397, 70, 1487, 70 },
    rspritearr[40] = { 36, 74, 117, 70, 194, 74, 276, 72, 393, 77, 472, 76, 550, 78, 630, 79, 743, 95, 842, 95, 941, 95, 1039, 95 },
    ringspritearr[30] = { 7, 56, 74, 52, 142, 44, 210, 35, 279, 25, 348, 16, 405, 25, 464, 35, 523, 44, 584, 52 },
    bossarr[6] = { 596, 202, 840, 244 }, bossCararr[6] = { 18, 248, 309, 247 }, bossEarr[16] = { 31, 329, 381, 294, 711, 261, 1024, 248, 1307, 247 },
    bossMarr[16] = { 41, 247, 326, 247, 604, 246, 899, 246, 1185, 247 }, bosscollarr[6] = { 42, 246, 320, 247 }, enemies1_Cord[10] = { 184, 117, 330 ,105 ,471 ,104 },
    Enemies2Arr[20] = { 418, 80, 516, 76, 603, 82, 730, 88 }, Enemies2count = 0 ,
    boss2arr[20] = { 38,70,170,71,305,69,438,68,36,72,172,73,314,64,434,67 }, boss2count = 0, boss2Marr[10] = { 85,117,213,121,348,117 }, boss2Mcount = 0,
    t = 0, vxt = 0, vyt = -10, y2 = 72, z = 104, vx = 0, vy = 0, Boss2Destruction[20] = {297, 81, 417, 115, 146, 112}, bossdest=0;

bool   lvl1 = 1, lvl2 = 0, booly = 0, bossreachl = 0, bossreachr = 1, enemyReachL = 0, enemyReachR = 1, baby = 0, Pausebool=0, 
       Boss2ReachLeft = 0, Boss2ReachRight = 1, r = 0;
string HighestScorer;


struct scores
{
    string name;
    int scored;
};
scores players[20];
scores currscore;


//window settings.
RenderWindow window1(VideoMode(1000, 550), "Sonic The Hedgehog");


//closing window.
void closing()
{
    Event event;
    while (window1.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window1.close();
        }
    }
}


//When Escape is pressed.
void Escape1()
{
    Text pause[3];

    pause[1].setString("Resume");
    pause[1].setFont(font);
    pause[1].setFillColor(Color::White);
    pause[1].setPosition(400, 245);
    pause[1].setCharacterSize(50);
    pause[2].setString("Main Menu");
    pause[2].setFont(font);
    pause[1].setFillColor(Color::White);
    pause[2].setPosition(400, 295);
    pause[2].setCharacterSize(50);

    while (true)
    {

        Vector2i  mousep = Mouse::getPosition(window1);
        Levels_Music1.pause();
        bossfight_music.pause();

        closing();

        if ((mousep.x >= 400 && mousep.x <= 540) && (mousep.y >= 258 && mousep.y <= 301))
        {
            pause[1].setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                break;
            }
        }
        else
        {
                pause[1].setFillColor(Color::White);
           
        }
        if ((mousep.x >= 400 && mousep.x <= 600) && (mousep.y >= 312 && mousep.y <= 351))
        {
            pause[2].setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Pausebool = 1;
                break;
            }
        }
        else
        {
                pause[2].setFillColor(Color::White);
        }






        window1.clear();
        window1.draw(pause[1]);
        window1.draw(pause[2]);
        window1.display();
    }

}


//end of level.
void LevelEnding(int l)
{
    int endingvars[7] = {}, countingscore = 0, check=0;
    string s10;

    //fireworks at the end.
    ending_music1.loadFromFile("Music/fireworks.ogg");
    ending_music.setBuffer(ending_music1);
    ending_music.play();
    ending_music.setLoop(true);


    controls.loadFromFile("Sprites/screens.png");
    ending.loadFromFile("Sprites/misc.png");
    ending1[4].setTexture(controls);
    ending1[4].setTextureRect(IntRect(1000, 50, 1000, 550));
    for (int i = 1; i <= 7; i++)
    {
        ending1[i].setTexture(ending);
    }

    ending1[1].setTextureRect(IntRect(7, 500, 46, 85));
    ending1[3].setTextureRect(IntRect(17, 600, 67, 94));
    ending1[2].setTextureRect(IntRect(14, 698, 66, 83));
    ending1[5].setTextureRect(IntRect(1, 177, 267, 268));
    ending1[6].setTextureRect(IntRect(0, 450, 174, 50));
    ending1[7].setTextureRect(IntRect(7, 815, 202, 50));

    ending1[1].setPosition(1200, 250);
    ending1[2].setPosition(1200, 250);
    ending1[3].setPosition(1200, 250);
    ending1[5].setPosition(350, -300);
    ending1[6].setPosition(-200, 200);
    ending1[7].setPosition(350, 750);

    countingscores.setFont(font);
    countingscores.setFillColor(Color::White);
    countingscores.setCharacterSize(50);
    countingscores.setPosition(800, -1000);
    countingscores.setString("0");

    while (window1.isOpen())
    {
        Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window1.close();
                titlescreen_music.stop();
            }
            if (event.type == Event::KeyPressed)
                check = 1;
        }
        if (check == 1)
            break;

        if (ending1[5].getPosition().y < 150)
        {
            endingvars[1]++;
            ending1[5].move(0, endingvars[1]);
        }
        if (ending1[6].getPosition().x < 400)
        {
            endingvars[3]++;
            ending1[6].move(endingvars[3], 0);
        }
        if (ending1[l].getPosition().x > 470)
        {
            endingvars[2]--;
            ending1[l].move(endingvars[2], 0);
        }
        if (ending1[7].getPosition().y > 350)
        {
            endingvars[4]--;
            ending1[7].move(0, endingvars[4]);
        }
        if (countingscores.getPosition().y < 300)
        {
            endingvars[5]++;
            countingscores.move(0, endingvars[5]);
        }
        if (countingscores.getPosition().y >= 300)
        {
            if (countingscore < currscore.scored)
                countingscore += 100;
            s10 = to_string(countingscore);
            countingscores.setString(s10);
        }

        window1.clear();
        window1.draw(ending1[4]);
        window1.draw(ending1[5]);
        window1.draw(ending1[l]);
        window1.draw(ending1[6]);
        window1.draw(countingscores);
        window1.draw(ending1[7]);
        window1.display();
    }
    ending_music.stop();
}


//score saving function.
void SaveScore()
{
    ofstream scoress;
    scoress.open("saves/scores.txt");

    for (int i = 0; i < 20; i++)
    {
        scoress << players[i].name<<endl;
        scoress << players[i].scored<<endl;
    }
    scoress << endl;
}

//Level 2 boss.
void boss2Movemnt()
{
   
    boss1.setTextureRect(IntRect(boss2Marr[boss2Mcount], 602, boss2Marr[boss2Mcount + 1], 87));
    boss2Mcount += 2;
    if (boss2Mcount == 6) {
        boss2Mcount = 0;
    }
    if (Boss2ReachLeft == 0 && t <= 120)
    {
        vx -= 1;
        boss1.move(vx, 0);
        t = 0;
    }

    if (boss1.getPosition().x <= 40) {

        boss1.setScale(1, 1);
        boss1.setTextureRect(IntRect(438, y2, 68, z));
        Boss2ReachLeft = 1;
        Boss2ReachRight = 0;
        vx = 0;
        t++;
        if (sonic1.getGlobalBounds().intersects(boss1.getGlobalBounds())) 
        {
            boss1.setTextureRect(IntRect(235, 435, 72, 134));
            yvel = -22;
            bosslives -= 1;
        }

    }

    if (Boss2ReachRight == 0 && t <= 120)
    {
        vx += 1;
        boss1.move(vx, 0);
        t = 0;
    }


    if (boss1.getPosition().x >= 950)
    {
        boss1.setScale(-1, 1);
        boss1.setTextureRect(IntRect(438, y2, 68, z));
        Boss2ReachLeft = 0;
        Boss2ReachRight = 1;
        vx = 0;
        t++;
        if (sonic1.getGlobalBounds().intersects(boss1.getGlobalBounds()))
        {
            boss1.setTextureRect(IntRect(235, 435, 72, 134));
            yvel = -22;
            bosslives -= 1;
        }

    }
}


//boss entering with egg.
void BossEntrance() {

    boss1.setTextureRect(IntRect(bossarr[bosscount], 28, bossarr[bosscount + 1], 132));
    bosscount += 2;
    boss1.setPosition(686, 100);
    if (bosscount == 4) {
        bosscount = 0;
        boss1.setPosition(750, 100);
    }

    if (y != 245) {
        y += 5;
    }
    boss1.move(0, y);

    bossCar1.setTextureRect(IntRect(bossCararr[bossCarcount], 75, bossCararr[bossCarcount + 1], 162));
    bossCarcount += 2;

    if (bossCarcount == 4) {
        bossCarcount = 0;

    }
}


//car entrance.
void BossEntrance2() {

    bossE.setTextureRect(IntRect(bossEarr[bossEcount], 216, bossEarr[bossEcount + 1], 158));
    bossE.setPosition(655, 350);
    bossEcount += 2;
}


//boss movement.
void BossMovemnt()
{
    if (!sonic1.getGlobalBounds().intersects(bossM.getGlobalBounds()))
    {
        bossM.setTextureRect(IntRect(bossMarr[bossMcount], 434, bossMarr[bossMcount + 1], 136));
        bossMcount += 2;
        if (bossMcount == 10)
        {
            bossMcount = 6;
        }
    }

    if (bossreachl == 0)
    {
        bossspeed -= 0.3;
        bossM.move(bossspeed, 0);
    }


    if (bossM.getPosition().x <= 60)
    {
        bossM.setScale(-1, 1);
        bossM.move(200, 0);
        bossreachl = 1;
        bossreachr = 0;
        bossspeed = 0;
    }


    if (bossreachr == 0)
    {
        bossspeed += 0.3;
        bossM.move(bossspeed, 0);
    }


    if (bossM.getPosition().x >= 963)
    {
        bossM.setScale(1, 1);
        bossM.move(-200, 0);
        bossreachl = 0;
        bossreachr = 1;
        bossspeed = 0;
    }

    if (sonic1.getGlobalBounds().intersects(bossM.getGlobalBounds()) && sonic1.getPosition().y < bossM.getPosition().y)
    {
        bossM.setTextureRect(IntRect(bosscollarr[bosshit], 620, bosscollarr[bosshit + 1], 154));
        bosshit += 2;
        if (bosshit == 4)
        {
            bosshit = 0;
        }
        yvel = -15;
        bosslives--;
    }

}


//enemies of level 2.
void enemyMovement2()
{

    for (int i = 0; i < 10; i++)
    {
        if (sonic1.getGlobalBounds().intersects(enemy1[i].getGlobalBounds()))
        {
            enemy1[i].setPosition(-1000, -1000);
            yvel = -15;
            currscore.scored += 200;
        }
    }

    for (int i = 0; i < 10; i++)
    {
            enemy1[i].setTextureRect(IntRect(Enemies2Arr[Enemies2count], 13, Enemies2Arr[Enemies2count + 1], 53));
    }
    Enemies2count += 2;
    if (Enemies2count == 8)
        Enemies2count = 0;


    for (int i = 0; i < 10; i++)
    {
            if (enemyReachL == false)
            {
                enemySpeed -= 0.2;
                enemy1[i].move(enemySpeed, 0);
            }

            if (enemySpeed <= -30)
            {
                enemyReachL = true;
                enemyReachR = false;
                enemySpeed = 0;
            }

            if (enemyReachR == false)
            {
                enemySpeed += 0.2;
                enemy1[i].move(enemySpeed, 0);
            }

            if (enemySpeed >= 30)
            {
                enemyReachR = true;
                enemyReachL = false;
                enemySpeed = 0;
            }
    }
}


//enemy movment.
void enemyMovement()
{

    for (int i = 0; i < 10; i++)
    {
        if (sonic1.getGlobalBounds().intersects(enemy1[i].getGlobalBounds()))
        {
            enemy1[i].setPosition(-1000, -1000);
            yvel = -15;
            currscore.scored += 200;
        }
    }

    for (int i = 0; i < 10; i++)
    {
            enemy1[i].setTextureRect(IntRect(enemies1_Cord[counter], 229, enemies1_Cord[counter + 1], 80));
    }
    counter += 2;
    if (counter == 6)
        counter = 0;

    for (int i = 0; i < 10; i++)
    {
            if (enemyReachL == false)
            {
                enemySpeed -= 0.2;
                enemy1[i].move(enemySpeed, 0);

            }

            if (enemySpeed <= -30)
            {
                enemyReachL = true;
                enemyReachR = false;
                enemySpeed = 0;
            }

            if (enemyReachR == false)
            {
                enemySpeed += 0.2;
                enemy1[i].move(enemySpeed, 0);
            }

            if (enemySpeed >= 30)
            {
                enemyReachR = true;
                enemyReachL = false;
                enemySpeed = 0;
            }
    }
}


//rings animation function to call in all levels.
void ringsanimation()
{

    ring_rect += 2;
    if (ring_rect == 20)
    {
        ring_rect = 0;
    }
    for (int i = 1; i <= 130; i++)
        ring1[i].setTextureRect(IntRect(ringspritearr[ring_rect], 5, ringspritearr[ring_rect + 1], 56));
}


//score and rings tracking function.
void scoreandrings()
{
    scoretext.setFont(font);
    scoretext.setCharacterSize(30);
    scoretext.setString("Score");
    scoretext.setFillColor(Color::White);
    scoretext.setPosition(15, 10);
    ringstext.setFont(font);
    ringstext.setCharacterSize(30);
    ringstext.setString("Rings");
    ringstext.setFillColor(Color::White);
    ringstext.setPosition(15, 35);


    string s1, s2;
    s1 = to_string(scoredrings);
    s2 = to_string(currscore.scored);
    scoretrack.setFont(font);
    scoretrack.setFillColor(Color::White);
    scoretrack.setCharacterSize(30);
    scoretrack.setString(s2);
    scoretrack.setPosition(150, 10);
    ringstrack.setFont(font);
    ringstrack.setFillColor(Color::White);
    ringstrack.setCharacterSize(30);
    ringstrack.setString(s1);
    ringstrack.setPosition(150, 35);
}


//background scrolling right.
void backgroundscrollr(int x)
{
    //background scrolling.
    if (sonic1.getPosition().x >= 400)
    {
        background_level1[x].move(-10, 0);
        sonic1.move(-15, 0);
        for (int i = 1; i < 131; i++)
        {
            ring1[i].move(-10, 0);
        }
        for (int i = 1; i < 10; i++)
        {
            enemy1[i].move(-10, 0);
        }
        for (int i = 0; i < 5; i++)
        {
            springs1[i].move(-10, 0);
        }
    }
}


//background scrolling left.
void backgroundscrolll(int x)
{
    //background scrolling.
    if (sonic1.getPosition().x <= 400 && background_level1[x].getPosition().x != 0)
    {
        background_level1[x].move(10, 0);
        sonic1.move(15, 0);
        for (int i = 1; i < 131; i++)
        {
            ring1[i].move(10, 0);
        }
        for (int i = 1; i < 10; i++)
        {
            enemy1[i].move(10, 0);
        }
        for (int i = 0; i < 5; i++)
        {
            springs1[i].move(10, 0);
        }
    }
}


//Rings collision.
void collision(Sprite ring[])
{
    for (int i = 1; i < 131; i++)
    {
        if (sonic1.getGlobalBounds().intersects(ring[i].getGlobalBounds()))
        {
            coin_sound.play();
            scoredrings++;
            currscore.scored += 100;
            ring[i].setPosition(-1000, -1000);
        }
    }
}


//springs to jump higher.
void Springss()
{
    for (int i = 0; i < 5; i++)
    {
        if (spri != i)
        {
            springs1[i].setTextureRect(IntRect(80, 558, 64, 42));
            springs1[i].setPosition(springs1[i].getPosition().x, ground+40);
        }

        if (sonic1.getGlobalBounds().intersects(springs1[i].getGlobalBounds()) && (sonic1.getPosition().y < springs1[i].getPosition().y - 40))
        {
            springs1[i].setTextureRect(IntRect(156, 576, 68, 24));
            spri = i;
            yvel = -27;
            break;
        }
        else if ((sonic1.getGlobalBounds().intersects(springs1[i].getGlobalBounds())) && (sonic1.getPosition().y >= springs1[i].getPosition().y-80) && (sonic1.getPosition().x < springs1[i].getPosition().x))
        {
            sonic1.move(-15, 0);
        }
        else if ((sonic1.getGlobalBounds().intersects(springs1[i].getGlobalBounds())) && (sonic1.getPosition().y >= springs1[i].getPosition().y - 80) && (sonic1.getPosition().x > springs1[i].getPosition().x))
        {
            sonic1.move(15, 0);
        }

        if (spri == i)
        {
            springs1[i].setTextureRect(IntRect(225, 520, 64, 100));
            springs1[i].setPosition(springs1[i].getPosition().x, ground);
            spri = -1;
        }
    }
}


//moving character func.
void moving(int x)
{
    if (!Keyboard::isKeyPressed(Keyboard::Right))
    {
        mover = 0;
        timedanimation2 = 0;
    }
    if (!Keyboard::isKeyPressed(Keyboard::Left))
    {
        movel = 0;
        timedanimation4 = 0;
    }

    if (!Keyboard::isKeyPressed(Keyboard::Up) && sonic1.getPosition().y == ground)
    {
        moveu = 0;
    }

    if (!Keyboard::isKeyPressed(Keyboard::Down))
    {
        moved = 0;
    }


    //first position.
    timedanimation1++;
    sonic1.setTextureRect(IntRect(sspritearr[notmoving], 176, sspritearr[notmoving + 1], 94));
    timedanimation3++;
    if (timedanimation3 == 20)
    {
        if (timedanimation1 > 0)
            notmoving += 2;
        if (notmoving == 10 && timedanimation1 <= 20)
            notmoving = 6;
        else if (notmoving == 22 && timedanimation1 <= 80)
            notmoving = 16;
        else if (notmoving == 34)
            notmoving = 24;
        timedanimation3 = 0;
    }

    //moving left.
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        sonic1.setScale(-1.f, 1.f);
        timedanimation1 = -100;
        notmoving = 0;
        if (background_level1[x].getPosition().x != 0)
            sonic1.move(-15.0f, 0.0f);

        if (background_level1[x].getPosition().x == -15000 && sonic1.getPosition().x <= 80)
        {
            sonic1.move(15.0f, 0.0f);
        }
        timedanimation4++;
        sonic1.setTextureRect(IntRect(rspritearr[movel], 863, rspritearr[movel + 1], 86));
        movel += 2;
        if (movel == 8 && timedanimation4 <= 20)
            movel = 0;
        else if (movel == 16 && timedanimation4 <= 50)
            movel = 8;
        else if (movel == 24)
            movel = 16;
    }

    //moving right.
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        sonic1.setScale(1.f, 1.f);
        sonic1.move(15.0f, 0.0f);
        if (background_level1[x].getPosition().x == -15000 && sonic1.getPosition().x >= 920)
        {
            sonic1.move(-15.0f, 0.0f);
        }
        timedanimation1 = -100;
        notmoving = 0;
        timedanimation2++;
        sonic1.setTextureRect(IntRect(rspritearr[mover], 863, rspritearr[mover + 1], 86));
        mover += 2;
        if (mover == 8 && timedanimation2 <= 20)
            mover = 0;
        else if (mover == 16 && timedanimation2 <= 50)
            mover = 8;
        else if (mover == 24)
            mover = 16;
    }

    //spin .
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        notmoving = 0;
        timedanimation1 = -100;
        sonic1.setTextureRect(IntRect(uspritearr[moved], 337, uspritearr[moved + 1], 70));
        moved += 2;
        if (moved == 10)
        {
            moved = 0;
        }
    }

    //jumping.
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        notmoving = 0;
        timedanimation1 = -100;
        yvel += 1;
        ypos += yvel;

    }

    if (sonic1.getPosition().y < ground)
    {
        sonic1.setTextureRect(IntRect(uspritearr[moveu], 337, uspritearr[moveu + 1], 70));
        moveu += 2;
        if (moveu == 10)
            moveu = 0;
    }

    //gravity.
    if (ypos > ground)
        yvel = -24;

   

    if (!Keyboard::isKeyPressed(Keyboard::Up)) 
    {
        if (ypos < ground) 
        {
            ypos = sonic1.getPosition().y;
            yvel += 1;
            ypos += yvel;
        }
    }

    if (sonic1.getPosition().y > ground)
    {
        ypos = ground;
    }
        sonic1.setPosition(sonic1.getPosition().x, ypos);

}


//Level 2.
void Level2()
{
    bosslives = 15;
    window1.setFramerateLimit(40);
    menu_music.stop();
    sonic1.setPosition(15, ground);

    int t10 = 0;
    xpos = 0;
    ring_starting_position = 400;


    //background.
    background_level_1.loadFromFile("Sprites/Level2.png");
    background_level1[2].setTexture(background_level_1);
    background_level1[2].setPosition(0, 0);


    //Level 1 background music.
    Levels_Music.loadFromFile("Music/Star Light Zone.ogg");
    Levels_Music1.setBuffer(Levels_Music);
    Levels_Music1.play();


    //enemies.
    enemy.loadFromFile("Sprites/enemies2.png");
    for (int i = 0; i < 10; i++)
    {
        enemy1[i].setTexture(enemy);
        enemy1[i].setPosition(xpos, ground+40);
        xpos += 1400;
    }

    //rings positions.
    ring1[1].setPosition(ring_starting_position += 50, 270);
    ring1[2].setPosition(ring_starting_position += 35, 210);
    ring1[3].setPosition(ring_starting_position += 50, 210);
    ring1[4].setPosition(ring_starting_position += 50, 270);
    ring1[5].setPosition(ring_starting_position -= 50, 330);
    ring1[6].setPosition(ring_starting_position -= 50, 330);
    ring1[7].setPosition(ring_starting_position += 1000, 50);
    for (int i = 8; i <= 12; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 50);
    }
    ring1[13].setPosition(ring_starting_position += 1000, 100);
    for (int i = 14; i <= 18; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 100);
    }
    ring1[19].setPosition(ring_starting_position -= 50, 200);
    for (int i = 20; i <= 22; i++)
    {
        ring1[i].setPosition(ring_starting_position -= 50, 200);
    }
    ring1[23].setPosition(ring_starting_position += 100, 280);
    ring1[24].setPosition(ring_starting_position -= 50, 280);
    ring1[25].setPosition(ring_starting_position += 950, 190);
    ring1[26].setPosition(ring_starting_position += 50, 220);
    ring1[27].setPosition(ring_starting_position += 50, 190);
    ring1[28].setPosition(ring_starting_position += 50, 220);
    ring1[29].setPosition(ring_starting_position += 50, 190);
    ring1[30].setPosition(ring_starting_position += 50, 220);
    ring1[31].setPosition(ring_starting_position += 50, 190);
    ring1[32].setPosition(ring_starting_position += 50, 220);
    ring1[33].setPosition(ring_starting_position += 800, 150);
    for (int i = 34; i <= 40; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 150);
    }
    ring1[41].setPosition(ring_starting_position += 850, 110);
    ring1[42].setPosition(ring_starting_position += 50, 90);
    ring1[43].setPosition(ring_starting_position += 50, 110);
    ring1[44].setPosition(ring_starting_position += 50, 90);
    ring1[45].setPosition(ring_starting_position += 50, 110);
    ring1[46].setPosition(ring_starting_position += 50, 90);
    ring1[47].setPosition(ring_starting_position += 50, 110);
    ring1[48].setPosition(ring_starting_position += 800, 100);
    for (int i = 49; i < 60; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 80);
    }
    ring1[60].setPosition(ring_starting_position += 750, 400);
    ring1[61].setPosition(ring_starting_position += 850, 110);
    ring1[62].setPosition(ring_starting_position += 50, 90);
    ring1[63].setPosition(ring_starting_position += 50, 110);
    ring1[64].setPosition(ring_starting_position += 800, 90);
    ring1[65].setPosition(ring_starting_position += 50, 110);
    ring1[66].setPosition(ring_starting_position += 50, 90);
    ring1[67].setPosition(ring_starting_position += 800, 400);
    for (int i = 68; i < 75; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 400);
    }
    ring1[75].setPosition(ring_starting_position += 750, 110);
    ring1[76].setPosition(ring_starting_position += 50, 130);
    ring1[77].setPosition(ring_starting_position += 50, 110);
    ring1[78].setPosition(ring_starting_position += 750, 130);
    ring1[79].setPosition(ring_starting_position += 50, 110);
    ring1[80].setPosition(ring_starting_position += 50, 130);

    //springs positions.
    springs1[0].setPosition(1700, ground + 90);
    springs1[1].setPosition(2800, ground + 90);
    springs1[2].setPosition(6200, ground + 90);
    springs1[3].setPosition(7700, ground + 90);

    //level 1 boss fight music.
    bossfight1_music.loadFromFile("Music/Boss.ogg");
    bossfight_music.setBuffer(bossfight1_music);

    boss.loadFromFile("Sprites/metalsonic.png");
    boss1.setTexture(boss);
    boss1.setPosition(686, 400);
    boss1.setScale(-1, 1);


    while (window1.isOpen())
    {
        //closing window.
        closing();

        //pause.
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            Escape1();
            if (Pausebool)
                break;
            Levels_Music1.play();
        }

        //using moving function for character movement.
        moving(2);

        //boss fight music.
        if (background_level1[2].getPosition().x == -15000 && bossfight_music.getStatus() != bossfight_music.Playing)
        {
            Levels_Music1.stop();
            bossfight_music.play();
        }


        if (background_level1[2].getPosition().x == -15000 && bosslives > 0)
            boss2Movemnt();


        //animation of rings function.
        ringsanimation();

        //using ring collision function on the array of rings.
        collision(ring1);

        //using background scrolling right function.
        if (background_level1[2].getPosition().x != -15000)
            backgroundscrollr(2);

        //using background scrolling left function.
        if (background_level1[2].getPosition().x != -15000)
            backgroundscrolll(2);

        //trackig of rings and score.
        scoreandrings();

        //springs.
        Springss();

        //movement of enemies.
        enemyMovement2();

        //drawing.
        window1.clear();
        window1.draw(background_level1[2]);
        for (int i = 1; i <= 80; i++)
        {
            window1.draw(ring1[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            window1.draw(springs1[i]);
        }
        window1.draw(sonic1);
        if (background_level1[2].getPosition().x == -15000)
        {
            window1.draw(boss1);
        }
       if (bosslives == 0)
        {
            boss1.setTextureRect(IntRect(Boss2Destruction[bossdest], 717, Boss2Destruction[bossdest+1], 116));
            bossdest += 2;
            if (bossdest == 6)
                bossdest = 0;
            t10++;
            if (t10 == 150)
            {
                bossfight_music.stop();
                break;
            }
        }
        for (int i = 0; i < 10; i++) {
            window1.draw(enemy1[i]);
        }
        window1.draw(scoretext);
        window1.draw(ringstext);
        window1.draw(scoretrack);
        window1.draw(ringstrack);
        window1.display();
    }
}


//Level 1.
void Level1()
{
    bosslives = 30;
    window1.setFramerateLimit(40);
    menu_music.stop();
    sonic1.setPosition(15, ground);

    int t10 = 0;

    ring_starting_position = 200;

    //background.
    background_level_1.loadFromFile("Sprites/Level1.jpg");
    background_level1[1].setTexture(background_level_1);
    background_level1[1].setPosition(0, 0);


    //Level 1 background music.
    Levels_Music.loadFromFile("Music/Green Hill Zone.ogg");
    Levels_Music1.setBuffer(Levels_Music);
    Levels_Music1.play();
    Levels_Music1.setLoop(true);

    //enemies.
    enemy.loadFromFile("Sprites/enemies.png");
    for (int i = 0; i < 10; i++)
    {
        enemy1[i].setTexture(enemy);
    }


    for (int i = 0; i < 10; i++) {

        if (i == 3 || i == 6 || i == 8) {
            enemy1[i].setPosition(xpos, 320 - (i * 15));
        }

        else { enemy1[i].setPosition(xpos, 340); }
        xpos += 1400;
    }

    //rings positions.
    ring1[1].setPosition(ring_starting_position = ring_starting_position, 270);
    ring1[2].setPosition(ring_starting_position = ring_starting_position + 50, 270);
    ring1[3].setPosition(ring_starting_position = ring_starting_position + 40, 320);
    ring1[4].setPosition(ring_starting_position = ring_starting_position - 40, 390);
    ring1[5].setPosition(ring_starting_position = ring_starting_position - 50, 390);
    ring1[6].setPosition(ring_starting_position = ring_starting_position - 65, 350);
    ring1[7].setPosition(ring_starting_position = ring_starting_position - 25, 290);
    ring1[8].setPosition(ring_starting_position = ring_starting_position, 220);
    ring1[9].setPosition(ring_starting_position = ring_starting_position + 25, 170);
    ring1[10].setPosition(ring_starting_position = ring_starting_position + 50, 135);
    ring1[11].setPosition(ring_starting_position = ring_starting_position + 50, 135);

    ring1[12].setPosition(ring_starting_position = ring_starting_position + 150, 135);
    ring1[13].setPosition(ring_starting_position = ring_starting_position, 200);
    ring1[14].setPosition(ring_starting_position = ring_starting_position, 280);
    ring1[15].setPosition(ring_starting_position = ring_starting_position, 360);
    ring1[16].setPosition(ring_starting_position = ring_starting_position + 55, 135);
    ring1[17].setPosition(ring_starting_position = ring_starting_position + 55, 135);
    ring1[18].setPosition(ring_starting_position = ring_starting_position + 55, 135);
    ring1[19].setPosition(ring_starting_position = ring_starting_position - 110, 250);
    ring1[20].setPosition(ring_starting_position = ring_starting_position + 50, 250);
    ring1[21].setPosition(ring_starting_position = ring_starting_position + 50, 250);
    ring1[22].setPosition(ring_starting_position = ring_starting_position - 100, 360);
    ring1[23].setPosition(ring_starting_position = ring_starting_position + 50, 360);
    ring1[24].setPosition(ring_starting_position = ring_starting_position + 50, 360);

    ring1[25].setPosition(ring_starting_position += 100, 370);
    ring1[26].setPosition(ring_starting_position , 310);
    ring1[27].setPosition(ring_starting_position , 250);
    ring1[28].setPosition(ring_starting_position , 190);
    ring1[29].setPosition(ring_starting_position , 130);
    ring1[30].setPosition(ring_starting_position = ring_starting_position + 50, 135);
    ring1[31].setPosition(ring_starting_position = ring_starting_position + 25, 195);
    ring1[32].setPosition(ring_starting_position = ring_starting_position + 30, 260);
    ring1[33].setPosition(ring_starting_position = ring_starting_position + 30, 310);
    ring1[34].setPosition(ring_starting_position = ring_starting_position + 30, 360);
    ring1[35].setPosition(ring_starting_position += 50, 370);
    ring1[36].setPosition(ring_starting_position, 310);
    ring1[37].setPosition(ring_starting_position, 250);
    ring1[106].setPosition(ring_starting_position, 190);
    ring1[107].setPosition(ring_starting_position, 130);

    ring1[38].setPosition(ring_starting_position = ring_starting_position + 100, 165);
    ring1[39].setPosition(ring_starting_position = ring_starting_position + 50, 125);
    ring1[40].setPosition(ring_starting_position = ring_starting_position + 50, 125);
    ring1[41].setPosition(ring_starting_position = ring_starting_position + 50, 165);
    ring1[42].setPosition(ring_starting_position = ring_starting_position - 25, 230);
    ring1[43].setPosition(ring_starting_position = ring_starting_position - 50, 270);
    ring1[44].setPosition(ring_starting_position = ring_starting_position - 50, 340);
    ring1[45].setPosition(ring_starting_position = ring_starting_position + 50, 340);
    ring1[46].setPosition(ring_starting_position = ring_starting_position + 50, 340);
    ring1[47].setPosition(ring_starting_position = ring_starting_position + 50, 340);

    ring1[48].setPosition(ring_starting_position = ring_starting_position + 100, 140);
    ring1[49].setPosition(ring_starting_position = ring_starting_position + 50, 125);
    ring1[50].setPosition(ring_starting_position = ring_starting_position + 50, 125);
    ring1[51].setPosition(ring_starting_position = ring_starting_position + 50, 170);
    ring1[52].setPosition(ring_starting_position = ring_starting_position - 50, 230);
    ring1[53].setPosition(ring_starting_position = ring_starting_position + 50, 260);
    ring1[54].setPosition(ring_starting_position = ring_starting_position - 50, 330);
    ring1[55].setPosition(ring_starting_position = ring_starting_position - 50, 330);
    ring1[56].setPosition(ring_starting_position = ring_starting_position - 50, 290);
    ring1[57].setPosition(ring_starting_position = ring_starting_position + 500, 170);
    ring1[58].setPosition(ring_starting_position = ring_starting_position + 50, 120);

    ring1[59].setPosition(ring_starting_position = ring_starting_position + 50, 170);
    ring1[60].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[61].setPosition(ring_starting_position = ring_starting_position + 50, 170);
    ring1[62].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[63].setPosition(ring_starting_position = ring_starting_position + 50, 170);
    ring1[64].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[65].setPosition(ring_starting_position = ring_starting_position + 50, 170);
    ring1[66].setPosition(ring_starting_position = ring_starting_position + 500, 100);
    ring1[67].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[68].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[69].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[70].setPosition(ring_starting_position = ring_starting_position + 50, 25);
    ring1[71].setPosition(ring_starting_position = ring_starting_position + 50, 55);
    ring1[72].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[73].setPosition(ring_starting_position = ring_starting_position - 50, 135);
    ring1[74].setPosition(ring_starting_position = ring_starting_position - 50, 185);
    ring1[75].setPosition(ring_starting_position = ring_starting_position + 500, 150);
    ring1[76].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[77].setPosition(ring_starting_position = ring_starting_position + 50, 50);
    ring1[78].setPosition(ring_starting_position = ring_starting_position + 50, 100);
    ring1[79].setPosition(ring_starting_position = ring_starting_position + 50, 150);
    ring1[80].setPosition(ring_starting_position = ring_starting_position + 500, 200);
    ring1[81].setPosition(ring_starting_position = ring_starting_position + 50, 200);
    ring1[82].setPosition(ring_starting_position = ring_starting_position + 35, 250);
    ring1[83].setPosition(ring_starting_position = ring_starting_position - 35, 300);
    ring1[84].setPosition(ring_starting_position = ring_starting_position - 50, 300);
    ring1[85].setPosition(ring_starting_position = ring_starting_position - 35, 250);
    ring1[86].setPosition(ring_starting_position = ring_starting_position - 50, 180);
    ring1[87].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[88].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[89].setPosition(ring_starting_position = ring_starting_position + 50, 120);
    ring1[90].setPosition(ring_starting_position = ring_starting_position + 50, 180);
    ring1[91].setPosition(ring_starting_position = ring_starting_position + 50, 240);
    ring1[92].setPosition(ring_starting_position = ring_starting_position - 50, 300);
    ring1[93].setPosition(ring_starting_position = ring_starting_position - 50, 365);
    ring1[94].setPosition(ring_starting_position = ring_starting_position - 50, 365);
    ring1[95].setPosition(ring_starting_position = ring_starting_position - 50, 365);
    ring1[96].setPosition(ring_starting_position = ring_starting_position - 50, 300);
    ring1[97].setPosition(ring_starting_position = ring_starting_position - 35, 240);
    ring1[98].setPosition(ring_starting_position = ring_starting_position + 800, 200);
    ring1[99].setPosition(ring_starting_position = ring_starting_position + 50, 150);
    ring1[100].setPosition(ring_starting_position = ring_starting_position +50, 100);
    ring1[101].setPosition(ring_starting_position = ring_starting_position + 50, 150);
    ring1[102].setPosition(ring_starting_position = ring_starting_position + 50, 200);
    ring1[103].setPosition(ring_starting_position = ring_starting_position - 50, 260);
    ring1[104].setPosition(ring_starting_position = ring_starting_position - 50, 310);
    ring1[105].setPosition(ring_starting_position = ring_starting_position - 50, 260);

    for (int i = 106; i < 117; i++)
    {
        ring1[i].setPosition(ring_starting_position += 50, 80);
    }
    ring1[117].setPosition(ring_starting_position += 750, 400);
    ring1[118].setPosition(ring_starting_position += 850, 110);
    ring1[119].setPosition(ring_starting_position += 50, 90);
    ring1[120].setPosition(ring_starting_position += 50, 110);
    ring1[121].setPosition(ring_starting_position += 800, 90);
    ring1[122].setPosition(ring_starting_position += 50, 110);
    ring1[123].setPosition(ring_starting_position += 50, 90);
    ring1[124].setPosition(ring_starting_position += 800, 400);
   
    
    //level 1 boss fight music.
    bossfight1_music.loadFromFile("Music/Boss.ogg");
    bossfight_music.setBuffer(bossfight1_music);

    boss.loadFromFile("Sprites/boss.png");
    boss1.setTexture(boss);
    boss1.setPosition(750, 100);
    bossCar1.setTexture(boss);
    bossCar1.setPosition(655, 420);
    bossE.setTexture(boss);
    bossM.setTexture(boss);
    bossM.setPosition(655, 370);


    while (window1.isOpen())
    {
        //closing window.
        closing();

        //pause.
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            Escape1();
            if (Pausebool)
                break;
            Levels_Music1.play();
        }

        //using moving function for character movement.
        moving(1);

        //boss fight music.
        if (background_level1[1].getPosition().x == -15000 && bossfight_music.getStatus() != bossfight_music.Playing)
        {
            Levels_Music1.stop();
            bossfight_music.play();
        }

        if (y != 245 && background_level1[1].getPosition().x == -15000)
            BossEntrance();

        if (y == 245 && bossEcount < 10 && background_level1[1].getPosition().x == -15000)
            BossEntrance2();

        if (bossEcount >= 10 && background_level1[1].getPosition().x == -15000 && bosslives > 0)
            BossMovemnt();


        //animation of rings function.
        ringsanimation();

        //using ring collision function on the array of rings.
        collision(ring1);

        //using background scrolling right function.
        if (background_level1[1].getPosition().x != -15000)
            backgroundscrollr(1);

        //using background scrolling left function.
        if (background_level1[1].getPosition().x != -15000)
            backgroundscrolll(1);

        //trackig of rings and score.
        scoreandrings();

        //movement of enemies.
        enemyMovement();

        //drawing.
        window1.clear();
        window1.draw(background_level1[1]);
        for (int i = 1; i <= 124; i++)
        {
            window1.draw(ring1[i]);
        }
        window1.draw(sonic1);
        if (y != 245 && background_level1[1].getPosition().x == -15000)
        {
            window1.draw(boss1);
            window1.draw(bossCar1);
        }

        if (y == 245 && bossEcount < 10 && background_level1[1].getPosition().x == -15000)
        {
            window1.draw(bossE);
        }
        if (bossEcount >= 10 && background_level1[1].getPosition().x == -15000)
        {
            window1.draw(bossM);
        }
        if (bosslives == 0)
        {
            bossM.setTextureRect(IntRect(610, 613, 230, 153));
            t10++;
            if (t10 == 150)
            {
                bossfight_music.stop();
                break;
            }
        }
        for (int i = 0; i < 10; i++) {
            window1.draw(enemy1[i]);
        }
        window1.draw(scoretext);
        window1.draw(ringstext);
        window1.draw(scoretrack);
        window1.draw(ringstrack);
        window1.display();
    }
}


//leaderboard function.
void leaderboardFunc()
{
    int j = 0, yOfScores = 60, off = 1;
    string  s5, s6;
    nam.setFont(font);
    nam.setCharacterSize(40);
    nam.setFillColor(Color::White);
    scr.setFont(font);
    scr.setCharacterSize(40);
    scr.setFillColor(Color::White);
    highscore[1].setFont(font);
    highscore[1].setCharacterSize(40);
    highscore[1].setFillColor(Color::White);
    highscore[1].setPosition(700, 4);
    s6 = to_string(highestscore);
    highscore[1].setString(s6);
    highscore[2].setFont(font);
    highscore[2].setCharacterSize(40);
    highscore[2].setFillColor(Color::White);
    highscore[2].setPosition(200, 4);
    highscore[2].setString(HighestScorer);

    window1.clear();
    window1.draw(controls1[2]);
    window1.display();

    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        closing();

        nam.setString(players[j].name);
        s5 = to_string(players[j].scored);
        scr.setString(s5);

        nam.setPosition(810, yOfScores);
        scr.setPosition(430, yOfScores);
        if (off == 1)
        {
            window1.draw(highscore[1]);
            window1.draw(highscore[2]);
            window1.draw(nam);
            window1.draw(scr);
            window1.display();
        }
        j++;
        yOfScores += 23;
        if (j == scores_count || yOfScores == 60 + 23 * (scores_count - 1))
        {
            off = 0;
            j = 0;
            yOfScores = 60;
        }
    }
}


//get the scores from the text file to put it in the struct.
void stats()
{
    ifstream scoress;
    scoress.open("saves/scores.txt");
    scores_count = 0;

    if (scoress.fail())
    {
        cout << "Fail";
    }
    while (!scoress.eof())
    {
        scoress >> players[scores_count].name;
        scoress >> players[scores_count].scored;

        if (players[scores_count - 1].scored > highestscore)
        {
            highestscore = players[scores_count - 1].scored;
            HighestScorer = players[scores_count - 1].name;
        }
        if (players[scores_count-1].scored < LowestScore && players[scores_count-1].scored >=0 && scores_count-1>=0)
        {
            LowestScore = players[scores_count - 1].scored;
            LowestIndex = scores_count;
        }
        scores_count++;
    }
}


//knowing 3hich level is opened and which is not.
void LevelSelect()
{
    ifstream Lvlsi;
    Lvlsi.open("saves/Level.txt");

    if (Lvlsi.fail())
    {
        cout << "Fail";
    }
    while (!Lvlsi.eof())
    {
        Lvlsi >> Levels;
    }

    LvlSel[1].setString("Level 1");
    LvlSel[1].setFont(font);
    LvlSel[1].setPosition(440, 180);
    LvlSel[1].setCharacterSize(50);
    LvlSel[2].setString("Level 2");
    LvlSel[2].setFont(font);
    LvlSel[2].setPosition(440, 250);
    LvlSel[2].setCharacterSize(50);

    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        closing();

        Vector2i  mousep2 = Mouse::getPosition(window1);

        if (Levels >= 1)
        {
            LvlSel[1].setFillColor(Color::White);
        }
        if (Levels >= 2)
        {
            LvlSel[2].setFillColor(Color::White);
        }
        else
        {
            LvlSel[2].setFillColor(Color::Red);
        }

        if ((mousep2.x >= 439 && mousep2.x <= 603) && (mousep2.y >= 197 && mousep2.y <= 239) && Levels >= 1)
        {
            LvlSel[1].setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                lvl1 = 1;
                lvl2 = 0;
                break;
            }
        }
        if ((mousep2.x >= 439 && mousep2.x <= 610) && (mousep2.y >= 268 && mousep2.y <= 306) && Levels >= 2)
        {
            LvlSel[2].setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                lvl1 = 0;
                lvl2 = 1;
                break;
            }
        }

        window1.clear();
        window1.draw(LvlSel[1]);
        window1.draw(LvlSel[2]);
        window1.display();
    }
}


//start function.
void startfunc()
{
    
    menu2[6].setString("Type Your Name Then Press Enter");
    menu2[6].setFillColor(Color(63, 71, 204));
    menu2[6].setFont(font);
    menu2[6].setPosition(50, 300);
    menu2[6].setCharacterSize(30);
    currname.setPosition(180, 360);
    currname.setCharacterSize(30);
    currname.setFont(font);
    currname.setStyle(Text::Underlined);
    currname.setFillColor(Color(173, 148, 55));

    while (!Keyboard::isKeyPressed(Keyboard::Enter))
    {
        booly = 1;
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            booly = 0;
            break;
        }
        while (window1.pollEvent(event2))
        {
            currname.setString(currscore.name);
            if (event2.type == Event::KeyPressed)
            {
                switch (event2.key.code)
                {
                case Keyboard::A:
                    currscore.name.push_back('A');
                    break;
                case Keyboard::B:
                    currscore.name.push_back('B');
                    break;
                case Keyboard::C:
                    currscore.name.push_back('C');
                    break;
                case Keyboard::D:
                    currscore.name.push_back('D');
                    break;
                case Keyboard::E:
                    currscore.name.push_back('E');
                    break;
                case Keyboard::F:
                    currscore.name.push_back('F');
                    break;
                case Keyboard::G:
                    currscore.name.push_back('G');
                    break;
                case Keyboard::H:
                    currscore.name.push_back('H');
                    break;
                case Keyboard::I:
                    currscore.name.push_back('I');
                    break;
                case Keyboard::J:
                    currscore.name.push_back('J');
                    break;
                case Keyboard::K:
                    currscore.name.push_back('K');
                    break;
                case Keyboard::L:
                    currscore.name.push_back('L');
                    break;
                case Keyboard::M:
                    currscore.name.push_back('M');
                    break;
                case Keyboard::N:
                    currscore.name.push_back('N');
                    break;
                case Keyboard::O:
                    currscore.name.push_back('O');
                    break;
                case Keyboard::P:
                    currscore.name.push_back('P');
                    break;
                case Keyboard::Q:
                    currscore.name.push_back('Q');
                    break;
                case Keyboard::R:
                    currscore.name.push_back('R');
                    break;
                case Keyboard::S:
                    currscore.name.push_back('S');
                    break;
                case Keyboard::T:
                    currscore.name.push_back('T');
                    break;
                case Keyboard::U:
                    currscore.name.push_back('U');
                    break;
                case Keyboard::V:
                    currscore.name.push_back('V');
                    break;
                case Keyboard::W:
                    currscore.name.push_back('W');
                    break;
                case Keyboard::X:
                    currscore.name.push_back('X');
                    break;
                case Keyboard::Y:
                    currscore.name.push_back('Y');
                    break;
                case Keyboard::Z:
                    currscore.name.push_back('Z');
                    break;
                case Keyboard::BackSpace:
                    currscore.name.pop_back();
                    break;

                }
            }
            window1.clear();
            window1.draw(menu1);
            window1.draw(menu2[6]);
            window1.draw(currname);
            window1.display();
        }
    }
}


//main menu.
void menufunc()
{
    window1.setFramerateLimit(60);

    int p = 0;
    currscore = {};
    booly = 0;

    menu_music1.loadFromFile("Music/menu_music.ogg");
    menu_music.setBuffer(menu_music1);
    titlescreen_music.stop();
    menu_music.play();
    menu_music.setLoop(true);

    menu.loadFromFile("Sprites/menu.jpg");
    menu1.setTexture(menu);

    menu2[1].setString("Start");
    menu2[1].setFont(font);
    menu2[1].setPosition(10, 245);
    menu2[1].setCharacterSize(50);
    menu2[2].setString("Level Select");
    menu2[2].setFont(font);
    menu2[2].setPosition(10, 295);
    menu2[2].setCharacterSize(50);
    menu2[3].setString("Controls");
    menu2[3].setFont(font);
    menu2[3].setPosition(10, 345);
    menu2[3].setCharacterSize(50);
    menu2[4].setString("Leaderboard");
    menu2[4].setFont(font);
    menu2[4].setPosition(10, 395);
    menu2[4].setCharacterSize(50);
    menu2[5].setString("exit");
    menu2[5].setFont(font);
    menu2[5].setPosition(10, 445);
    menu2[5].setCharacterSize(50);

    controls.loadFromFile("Sprites/screens.png");
    controls1[1].setTexture(controls);
    controls1[2].setTexture(controls);

    controls1[1].setTextureRect(IntRect(19, 0, 1000, 550));
    controls1[2].setTextureRect(IntRect(3075, 0, 1000, 550));

    stats();

    while (true)
    {
        Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window1.close();
                titlescreen_music.stop();
            }

            //to move between options in the menu.
            if (event.type == Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Down))
                {
                    p++;
                    if (p == 6)
                        p = 1;
                    menu2[p].setFillColor(Color::Red);
                }
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    p--;
                    if (p == 0)
                        p = 5;
                    menu2[p].setFillColor(Color::Red);
                }
                window1.setKeyRepeatEnabled(false);
            }
        }

        //mouse position at any time.
        Vector2i  mousep = Mouse::getPosition(window1);

        //when space is pressed after selecting an option.
        if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)) && p == 1)
        {
            startfunc();
            if (booly == 1)
            {
                titlescreen_music.stop();
                break;
            }
        }
        if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)) && p == 2)
        {
            LevelSelect();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)) && p == 3)
        {
            while (!Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window1.clear();
                window1.draw(controls1[1]);
                window1.display();
            }
        }
        if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)) && p == 4)
        {
            leaderboardFunc();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)) && p == 5)
        {
            break;
        }

        //when using mouse to select any option in menu.
        if ((mousep.x >= 10 && mousep.x <= 147) && (mousep.y >= 258 && mousep.y <= 301))
        {
            p = 0;
            menu2[1].setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
            {
                startfunc();
                if (booly == 1)
                {
                    titlescreen_music.stop();
                    break;
                }
            }
        }
        else
        {
            if (p != 1)
            {
                coin_sound.play();
                menu2[1].setFillColor(Color(63, 71, 204));
            }
        }
        if ((mousep.x >= 10 && mousep.x <= 296) && (mousep.y >= 312 && mousep.y <= 351))
        {
            p = 0;
            menu2[2].setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
            {
                LevelSelect();
            }
        }
        else
        {
            if (p != 2)
            {
                coin_sound.play();
                menu2[2].setFillColor(Color(63, 71, 204));
            }
        }
        if ((mousep.x >= 10 && mousep.x <= 213) && (mousep.y >= 364 && mousep.y <= 401))
        {
            p = 0;
            menu2[3].setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
            {
                while (!Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window1.clear();
                    window1.draw(controls1[1]);
                    window1.display();
                }
            }
        }
        else
        {
            if (p != 3)
            {
                coin_sound.play();
                menu2[3].setFillColor(Color(173, 148, 55));
            }
        }
        if ((mousep.x >= 10 && mousep.x <= 307) && (mousep.y >= 414 && mousep.y <= 449))
        {
            p = 0;
            menu2[4].setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
            {
                leaderboardFunc();
            }
        }
        else
        {
            if (p != 4)
            {
                coin_sound.play();
                menu2[4].setFillColor(Color(173, 148, 55));
            }
        }
        if ((mousep.x >= 10 && mousep.x <= 103) && (mousep.y >= 460 && mousep.y <= 500))
        {
            p = 0;
            menu2[5].setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
            {
                break;
            }
        }
        else
        {
            if (p != 5)
            {
                coin_sound.play();
                menu2[5].setFillColor(Color(173, 148, 55));
            }
        }


        window1.clear();
        window1.draw(menu1);
        window1.draw(menu2[1]);
        window1.draw(menu2[2]);
        window1.draw(menu2[3]);
        window1.draw(menu2[4]);
        window1.draw(menu2[5]);
        window1.display();
    }
}


//Titlescreen.
void titlescreenfunc()
{
    window1.setFramerateLimit(8);
    int title = 0, check = 0;
    titlescreen_music1.loadFromFile("Music/01 Title Screen.ogg");
    titlescreen_music.setBuffer(titlescreen_music1);
    titlescreen_music.play();
    titlescreen_music.setLoop(true);


    titlescreen.loadFromFile("Sprites/background_titlescreen.png");

    titlescreen1[0].setTexture(titlescreen);
    titlescreen1[0].setTextureRect(IntRect(600, 0, 1000, 550));
    titlescreen1[1].setTexture(titlescreen);
    titlescreen1[1].setTextureRect(IntRect(5, 46, 576, 449));
    titlescreen1[1].setPosition(200, 50);
    titlescreen1[2].setTexture(titlescreen);
    titlescreen1[2].setPosition(400, 165);


    while (true)
    {
        Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window1.close();
                titlescreen_music.stop();
            }
            if (event.type == Event::KeyPressed)
                check = 1;
        }
        if (check == 1)
            break;

        titlescreen1[2].setTextureRect(IntRect(TitleSpriteArr[title], 574, TitleSpriteArr[title + 1], 172));
        title += 2;
        if (title == 16)
            title = 12;

        window1.clear();
        window1.draw(titlescreen1[0]);
        window1.draw(titlescreen1[1]);
        window1.draw(titlescreen1[2]);
        window1.display();

    }

    //sound plays to the end before leaving function.
    coin_sound.play();
    while (coin_sound.getStatus() == Sound::Playing);

}


//main game.
int main()
{
    //springs
    springs.loadFromFile("Sprites/items.png");
    for (int i = 0; i < 5; i++)
    {
        springs1[i].setTexture(springs);
    }

    //rings.
    ring.loadFromFile("Sprites/rings.png");
    for (int i = 0; i < 140; i++)
    {
        ring1[i].setTexture(ring);
    }

    //Game font.
    font.loadFromFile("Raisin Bread.ttf");

    //ring sound.
    coin_sound1.loadFromFile("Music/Mario-coin-sound.wav");
    coin_sound.setBuffer(coin_sound1);

    //Character first position.
    sonic.loadFromFile("Sprites/sonic.png");
    sonic1.setTexture(sonic);

    //titlescreen.
     titlescreenfunc();

   while (window1.isOpen())
   {
       closing();

       //menuscreen.
       menufunc();
       if (booly)
       {
           //level 1 start.
           if (lvl1 && !lvl2)
           {
               Level1();
               if (Pausebool)
               {
                   Pausebool = 0;
                   continue;
               }
               window1.setFramerateLimit(20);
               LevelEnding(1);
               window1.setFramerateLimit(40);

               players[LowestIndex - 1].scored = currscore.scored;
               players[LowestIndex - 1].name = currscore.name;
               SaveScore();

               //Saving current progress.
               ofstream LvlsO;
               LvlsO.open("saves/Level.txt");
               LvlsO << 2;

               lvl1 = 0;
               lvl2 = 1;
           }
           if (!lvl1 && lvl2)
           {
               Level2();
               if (Pausebool)
               {
                   Pausebool = 0;
                   continue;
               }
               window1.setFramerateLimit(20);
               LevelEnding(2);
               window1.setFramerateLimit(40);
               players[LowestIndex - 1].scored = currscore.scored;
               players[LowestIndex - 1].name = currscore.name;
               SaveScore();
               lvl1 = 1;
               lvl2 = 0;
           }
       }
       else
       {
           break;
       }
   }
}