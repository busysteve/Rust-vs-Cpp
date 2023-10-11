#include <vector>
#include <iostream>



std::vector< std::vector<double> > transpose_matrix(std::vector< std::vector<double> > &matrix ) {
    auto rows = matrix.size();
    auto cols = matrix[0].size();
    auto result = std::vector< std::vector<double> > ( cols, std::vector<double>(rows) ) ;

    for( auto i=0; i < rows; i++ ) {
        for( auto j=0; j < cols; j++ ) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

/*

fn dot_product(vec1: &Vec<f64>, vec2: &Vec<f64>) -> f64 {
    if vec1.len() != vec2.len() {
        panic!("Vector dimensions must match for dot product.");
    }

    let mut result = 0.0;
    for i in 0..vec1.len() {
        result += vec1[i] * vec2[i];
    }

    result
}

*/


std::vector< std::vector<double> > matrix_multiply( std::vector< std::vector<double> > &mat1, std::vector< std::vector<double> > &mat2) {
    auto rows1 = mat1.size();
    auto cols1 = mat1[0].size();
    auto rows2 = mat2.size();
    auto cols2 = mat2[0].size();

    if( cols1 != rows2 ) {
        throw("Matrix dimensions are not compatible for multiplication.");
    }

    auto result = std::vector< std::vector<double> > ( cols2, std::vector<double>(rows1) )  ;
    
    for( auto i=0; i < rows1; i++ ) {
        for( auto j=0; j < cols2; j++ ) {
            for( auto k=0; k < cols1; k++ ) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}


std::vector< std::vector<double> > build_matrix( int num_rows, int num_cols ) {
    std::vector< std::vector<double> > dynamic_matrix;

    for( auto i=0; i < num_rows; i++ ) {
        dynamic_matrix.push_back( std::vector<double>(0) );
        for( auto j=0; j < num_cols; j++ ) {
            dynamic_matrix[i].push_back( (double)i * num_cols + (double)j );
        }
        
    }

    return dynamic_matrix;
}


int main() {
    auto t1 = build_matrix( 5, 6 );
    auto t2 = transpose_matrix( t1 );
    auto rs = matrix_multiply( t1, t2);


    for( auto r : rs ) {
    	for( auto c : r )
    	    std::cout << c << " ";
    	std::cout << std::endl;
    }


    auto m1 = build_matrix( 500, 600 );

    auto m2 = transpose_matrix( m1 );

    for( auto _x=0; _x < 1; _x++ ) {
       auto result = matrix_multiply( m1, m2);
    }

    std::cout << "Done" << std::endl;
}



