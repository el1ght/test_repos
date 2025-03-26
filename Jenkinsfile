pipeline {
    agent {
        docker {
            image 'conanio/gcc10'
            args '-u root'
            customWorkspace '/tmp/jenkins'
        }
    }

    environment {
        BUILD_DIR = 'build'
        CXXFLAGS = "-w"
    }

    stages {
        stage('Build') {
            steps {
                sh 'cmake -S . -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_CXX_FLAGS="-w" -B ${BUILD_DIR}'
                sh 'cmake -DCMAKE_CXX_FLAGS="-w" --build ${BUILD_DIR}'
            }
        }

        stage('Test') {
            steps {
                // List files to confirm the build output is in place
                sh 'ls -la ./${BUILD_DIR}'

                // Check if the executable exists
                sh 'find ./${BUILD_DIR} -name "test_repos"'
                sh './${BUILD_DIR}/test_repos --gtest_output=xml:report.xml'
            }
        }
    }

    post {
        always {
            xunit (tools: [ GoogleTest(pattern: 'test_report.xml') ], skipPublishingChecks: false)
        }
    }
}