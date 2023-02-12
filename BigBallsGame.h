class BigBallsGame
{
    private:
    // Enum to track state of title screen
        typedef enum TitleScreenSteps { WAIT = 0, BIG, BLU, BALLS, TITLE} GameScreen;

    public:
        int position;
    //  Constructor
        BigBallsGame(int pos);
        BigBallsGame();
        void TitleScreen();
        void LoadLevelOne();
};