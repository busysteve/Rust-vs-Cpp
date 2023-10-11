fn transpose_matrix(matrix: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut result = vec![vec![0.0; rows]; cols];

    for i in 0..rows {
        for j in 0..cols {
            result[j][i] = matrix[i][j];
        }
    }

    result
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


fn matrix_multiply(mat1: &Vec<Vec<f64>>, mat2: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows1 = mat1.len();
    let cols1 = mat1[0].len();
    let rows2 = mat2.len();
    let cols2 = mat2[0].len();

    if cols1 != rows2 {
        panic!("Matrix dimensions are not compatible for multiplication.");
    }

    let mut result = vec![vec![0.0; cols2]; rows1];

    for i in 0..rows1 {
        for j in 0..cols2 {
            for k in 0..cols1 {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    result
}


fn build_matrix(num_rows: usize, num_cols: usize) -> Vec<Vec<f64> > {
    let mut dynamic_matrix = Vec::new();

    for i in 0..num_rows {
        let mut row = Vec::new();
        for j in 0..num_cols {
            row.push(i as f64 * num_cols as f64 + j as f64);
        }
        dynamic_matrix.push(row);
    }

    dynamic_matrix
}


fn main() {

    let t1 = build_matrix( 5, 6 );
    let t2 = transpose_matrix( &t1 );
    let rs = matrix_multiply( &t1, &t2);


    for r in rs {
    	for c in r {
    	    print!( "{} ", c );
    	}
    	println!();
    }




    let m1 = build_matrix( 500, 600 );

    let m2 = transpose_matrix(&m1);

    //println!("Original Matrix: {:?}", matrix);
    //println!("Transposed Matrix: {:?}", transposed);


    for _x in 0..1 {
       let _result = matrix_multiply(&m1, &m2);
    }

    println!("Done");
}



