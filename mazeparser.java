try
        {
            sc	= new Scanner(new FileInputStream(in_file));
        }
        catch (FileNotFoundException ex)
        {
            sc = new Scanner(System.in);
        }



        //first get the size of the maze
        int maze_rows = sc.nextInt();
        int maze_cols = sc.nextInt();


        int start_row,start_col,end_row,end_col;

        start_row = sc.nextInt();
        start_col = sc.nextInt();
        end_row = sc.nextInt();
        end_col = sc.nextInt();

        //now the connectivity
        int [][]connectivity = new int[maze_rows][maze_cols];

        for (i=0;i<maze_rows;i++)
        {
            for (j=0;j<maze_cols;j++)
            {
                connectivity[i][j] = sc.nextInt();
            }
        }
        sc.close();

        //initialize the graph
        Graph graph = new Graph(maze_rows*maze_cols);

        int leftmask = 8;
        int bottommask = 4;
        int topmask = 1;
        int rightmask = 2;

        for (i=0;i<connectivity.length;i++)
        {
            for (j=0;j<connectivity[i].length;j++)
            {
                if (((connectivity[i][j] & leftmask)==0) && (j>0))
                {
                    graph.setEdge(i*maze_cols+j,i*maze_cols+(j-1),1.0);
                }

                if (((connectivity[i][j] & bottommask)==0) && (i>0))
                {
                    graph.setEdge(i*maze_cols+j,(i-1)*maze_cols+j,1.0);
                }

                if (((connectivity[i][j] & rightmask)==0) && (j<maze_cols-1))
                {
                    graph.setEdge(i*maze_cols+j,i*maze_cols+(j+1),1.0);
                }

                if (((connectivity[i][j] & topmask)==0) && (i<maze_rows-1))
                {
                    graph.setEdge(i*maze_cols+j,(i+1)*maze_cols+j,1.0);
                }
            }
        }