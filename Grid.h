#ifndef GRID_H
#define GRID_H

/**
* @brief Stores all information for one player's game board.
* @authors Nifemi Fadahunsi, Michael Lane, Yuri Martinez, Anna Burns, Rokunuzjahan Rudro
*/
class Grid {
    public:
		/**
		* @pre none
		* @post m_grid made with initial value 'O' in each board position.
		*/
        Grid();
		
		/**
		* @pre none
		* @post m_grid is deleted
		*/
        ~Grid();
		
		/**
		* @brief Verifies that the player's inputs are valid, then places ship in their respective game board.
		* @pre none
		* @post '|' or '-' assigned to all game board positions the ship covers, depending on orientation of ship
		* @return True if ship is placed successfully, false otherwise.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param dir char value that specifies which direction from the ship's origin to place the ship.
		* @param size the number of board spaces the ship being placed will cover.
		*/
		bool setShip(int tRow, int tCol, char dir, int size);
		
		/**
		* @brief Assigns hit or miss symbol to position (tCol, tRow) in m_grid's game board.
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10, hitOrMiss = true or false if player's shot was a hit or miss
		*       respectively.
		* @post hit_ship's value assigned to m_grid[tRow][tCol] if hitOrMiss = true, miss_ship's value if 
		*        hitOrMiss = false.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param hitOrMiss variable that signals if the player's shot is a hit or a miss.
		*/
		void setValue(int tRow, int tCol, bool hitOrMiss);
		
		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10
		* @return Value at m_grid[tRow][tCol]
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		*/
		char getValue(int tRow, int tCol);

		/**
		* @brief Verifies that the player's inputted row and column are within m_grid's boundaries.
		* @pre none
		* @return True if tRow and tCol represent a valid board position, false otherwises.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		*/
		bool checkForValidPlacedCoordinates(int tRow, int tCol, int size); //doesn't use size anymore - yuri

		/**
		* @pre none
		* @post Current turn's player's board printed to terminal.
		*/
		void print_ships_Grid();
		
		/**
		* @pre none
		* @post opponent's board printed to terminal, where '|' and
		* '-' are replaced with '*'.
		*/
		void print_shots_Grid();
		
		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @post ship is placed and oriented above the origin location.
		* @return true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param size the number of spaces the ship will take up.
		*/
		bool checkUp(int tRow, int tCol, int size);
		
		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @post ship is placed and oriented below the origin location.
		* @return true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param size the number of spaces the ship will take up.
		*/
		bool checkDown(int tRow, int tCol, int size);
		
		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @post ship is placed and oriented to the right of the origin location.
		* @return true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param size the number of spaces the ship will take up.
		*/
		bool checkRight(int tRow, int tCol, int size);
		
		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @post ship is placed and oriented to the left of the origin location.
		* @return true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param tRow the target row the player is firing at.
		* @param tCol the target column the player is firing at.
		* @param size the number of spaces the ship will take up.
		*/
		bool checkLeft(int tRow, int tCol, int size);

		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @return true if ship number is on the grid, false if it is not
		* @param num the ship number
		*/
		bool checkShadow (int num);

		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @return the number at the row and column of the shadow grid
		* @param tRow the row number
		* @param tCol the column number
		*/
		int getShadow (int tRow, int tCol);

		/**
		* @pre 1 <= tRow <= 9, 1 <= tCol <= 10.
		* @post the shadow grid is set to 0 at the given row and column
		* @param tRow the row number
		* @param tCol the column number
		*/
		void setShadow(int tRow, int tCol);

    private:
		
		//game board for one player (each Grid object represents one player's board)
        char** m_grid;
		int** m_shadowGrid;
		const int rows = 10;
        const int cols = 11;
        char hit_ship = 'H';
        char miss_ship = 'M'; 
};
#endif