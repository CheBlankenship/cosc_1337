// Che Blankenship
class MovieData
{
    private:
        // Attributes
        string title, director;
        int year, time;
        double productionCosts, revenues;


	public:

        // Default
        MovieData()
        {
            cout << "Please set the parameters to create a object. " << '\n'
                 << "MovieData(s title, s director, i year, i time) " << '\n'
                 << "MovieData(s title, s director, i year, i time, d prodCost, d revenues) " << '\n';

        }

        // 1
        MovieData(string movieTitle, string movieDirector, int movieYear, int movieTime)
        {
            title = movieTitle;
            director = movieDirector;
            year = movieYear;
            time = movieTime;
        }

        // 2
        MovieData(string movieTitle, string movieDirector, int movieYear, int movieTime, double movieProdCost, double movieRevenues)
        {
            title = movieTitle;
            director = movieDirector;
            year = movieYear;
            time = movieTime;
            productionCosts = movieProdCost;
            revenues = movieRevenues;
        }

        // Get title
        string getTitle() const { return title; };
        // Get year
        string getDirector() const { return director; };
        // Get director
        int getYear() const { return year; };
        // Get time
        int getTime() const { return time; };
        // Get production costs
        double getProdCost() const { return productionCosts; };
        // Get revenues
        double getRevenues() const { return revenues; };


};
