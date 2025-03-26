pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }

    environment {
        BUILD_DIR = 'build'
    }

    stages {
        stage('Build') {
            steps {
                sh 'cmake -S . -DCMAKE_OSX_ARCHITECTURES=arm64 -B ${BUILD_DIR}'
                sh 'cmake --build ${BUILD_DIR}'
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